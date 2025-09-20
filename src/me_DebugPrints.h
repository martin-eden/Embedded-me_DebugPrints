// Debug prints interface

/*
  Author: Martin Eden
  Last mod.: 2025-09-20
*/

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_Duration.h>

namespace me_DebugPrints
{
  // Print unit
  void Print(TAsciiz Annotation, TUnit Unit);
  // Print address
  void Print(TAsciiz Annotation, TAddress Address);
  // Print boolean
  void Print(TAsciiz Annotation, TBool Bool);
  // Print address segment span
  void PrintAddrseg(TAsciiz Annotation, TAddressSegment AddrSeg);
  // Print memory segment data
  void PrintMemsegData(TAsciiz Annotation, TAddressSegment MemSeg);
  // Print iterator state
  void PrintIterator(TAsciiz Annotation, TAddrsegIterator Rator);
  // Print duration
  void PrintDuration(me_Duration::TDuration Duration);
}

/*
  2025-09-04
  2025-09-11
  2025-09-12
*/
