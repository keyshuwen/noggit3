// This file is part of Noggit3, licensed under GNU General Public License (version 3).

#pragma once

#include <math/frustum.hpp>
#include <math/vector_3d.hpp>
#include <noggit/MapHeaders.h>
#include <noggit/liquid_layer.hpp>

#include <vector>
#include <set>

class MPQFile;
class sExtendableArray;
class MapChunk;

class ChunkWater
{
public:
  ChunkWater() = delete;
  ChunkWater(float x, float z);

  void fromFile(MPQFile &f, size_t basePos);
  void save(sExtendableArray& adt, int base_pos, int& header_pos, int& current_pos);

  void draw ( math::frustum const& frustum
            , const float& cull_distance
            , const math::vector_3d& camera
            , liquid_render& render
            , opengl::scoped::use_program& water_shader
            , int animtime
            , int layer
            );

  bool is_visible (const float& cull_distance
                  , const math::frustum& frustum
                  , const math::vector_3d& camera
                  ) const;

  void autoGen(MapChunk* chunk, float factor);
  void CropWater(MapChunk* chunkTerrain);

  void setType(int type, size_t layer);
  int getType(size_t layer) const;
  bool hasData(size_t layer) const;

  void paintLiquid( math::vector_3d const& pos
                  , float radius
                  , int liquid_id
                  , bool add
                  , math::radians const& angle
                  , math::radians const& orientation
                  , bool lock
                  , math::vector_3d const& origin
                  , bool override_height
                  , bool override_liquid_id
                  , MapChunk* chunk
                  , float opacity_factor
                  );


  float xbase, zbase;

private:
  std::vector<math::vector_3d> _intersect_points;

  math::vector_3d vmin, vmax, vcenter;

  // remove empty layers
  void cleanup();
  // update every layer's render
  void update_layers();

  void copy_height_to_layer(liquid_layer& target, math::vector_3d const& pos, float radius);


  MH2O_Render Render;

  std::vector<liquid_layer> _layers;
};
