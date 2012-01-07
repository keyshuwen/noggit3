#ifndef __TREEVIEW_H
#define __TREEVIEW_H

#include <string>
#include <vector>

#include <noggit/UIButton.h>
#include <noggit/UIFrame.h>
#include <noggit/Directory.h>

class UIText;
class UITreeViewButton;

class UITreeView : public UIFrame
{
public:
  typedef UITreeView* Ptr;
  typedef std::vector<UITreeView::Ptr> Others;

  Others _others;
private:
  UITreeView::Ptr mParent;
  std::vector<UIText*> mFiles;
  Directory::Ptr mMyDir;
  UITreeViewButton * mMyButton;
  UIText * mMyText;
  const std::string& _directoryName;

  void (*mSelectFunction)( const std::string& );

  bool mExpanded;

public:
  UITreeView( float pX, float pY, const std::string& directoryName, Directory::Ptr pDirectory, UITreeView::Ptr pParent, void (*pSelectFunction)( const std::string& ) );

  void Expand();
  void Minimize();
  bool Expanded();
  void Toggle();

  void SetSelectFunction( void (*pSelectFunction)( const std::string& ) );
  const std::string& GetDirectoryName();
  UITreeView::Ptr GetParent()
  {
    return mParent;
  }

  void Move( int pEntries, UITreeView::Ptr pFrom );

  void render() const;

  UIFrame * processLeftClick( float mx,float my );
};

class UITreeViewButton : public UIButton
{
private:
  UITreeView::Ptr mTreeView;
public:
  UITreeViewButton( float x, float y, UITreeView::Ptr pTreeView );

  UIFrame::Ptr processLeftClick( float mx, float my );

  void SetClicked( bool pClicked );
};
#endif