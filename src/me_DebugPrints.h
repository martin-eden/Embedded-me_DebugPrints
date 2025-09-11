// Debug prints interface

/*
  Author: Martin Eden
  Last mod.: 2025-09-04
*/

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

namespace me_DebugPrints
{
  void Print(TAsciiz Annotation, TUnit Unit);

  void Print(TAsciiz Annotation, TAddress Address);

  void Print(TAsciiz Annotation, TBool Bool);

  void PrintAddrseg(TAsciiz Annotation, TAddressSegment AddrSeg);

  void PrintMemseg(TAsciiz Annotation, TAddressSegment MemSeg);

  void PrintIterator(TAsciiz Annotation, TAddrsegIterator Rator);

}

/*
  2025-09-04
*/
