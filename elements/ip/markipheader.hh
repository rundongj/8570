#ifndef MARKIPHEADER_HH
#define MARKIPHEADER_HH

/*
 * =c
 * MarkIPHeader([OFFSET])
 * =d
 *
 * Marks packets as IP packets by setting the IP Header annotation. The IP
 * header starts OFFSET bytes into the packet. Default OFFSET is 0. Does not
 * check length fields for sanity or shorten packets to the IP length; use
 * CheckIPHeader or CheckIPHeader2 for that.
 *
 * =a CheckIPHeader
 * =a CheckIPHeader2
 * =a StripIPHeader */

#include "element.hh"

class MarkIPHeader : public Element {

  int _offset;
  
 public:
  
  MarkIPHeader();
  
  const char *class_name() const		{ return "MarkIPHeader"; }
  int configure(const Vector<String> &, ErrorHandler *);
  
  MarkIPHeader *clone() const;

  Packet *simple_action(Packet *);
  
};

#endif
