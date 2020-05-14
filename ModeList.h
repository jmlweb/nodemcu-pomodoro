/*
  ModeList.h
*/
#ifndef ModeList_h
#define ModeList_h

#include "Arduino.h";
#include "Mode.h";

class ModeNode
{
  public:
    ModeNode(Mode mode);
    Mode getMode();
    ModeNode *next;
  private:
    Mode _mode;
};

ModeNode::ModeNode(Mode mode)
{
  _mode = mode;
  next = nullptr;
};

Mode ModeNode::getMode()
{
  return _mode;
}

class ModeList
{
  public:
    ModeList();
    void append(Mode mode);
    ModeNode getAt(int position);

  private:
    ModeNode *_head;
    ModeNode *_tail;
};

ModeList::ModeList()
{
  _head = nullptr;
  _tail = nullptr;
};

void ModeList::append(Mode mode)
{
  ModeNode node(mode);
  if (!_head) {
    *node.next = node;
    *_head = node;
    *_tail = node;
  } else {
    ModeNode tmp = node;
    tmp.next = _head;
    *_tail->next = tmp;
    *_tail = tmp;
  }
};

ModeNode ModeList::getAt(int position)
{
  ModeNode current = *_head;
  if (position == 0) {
    return current;
  }
  int i = 0;
  while (i <= position) {
    current = *current.next;
  }
  return current;
}

#endif
