// Debug prints interface

/*
  Author: Martin Eden
  Last mod.: 2025-12-28
*/

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

namespace me_DebugPrints
{
  // Print boolean
  void Print(TAsciiz Annotation, TBool Bool);
  // Print unit
  void Print(TAsciiz Annotation, TUnit Unit);
  // Print address
  void Print(TAsciiz Annotation, TAddress Address);
  // Print uint_4
  void Print(TAsciiz Annotation, TUint_4 Uint_4);
  // Print address segment span
  void PrintAddrseg(TAsciiz Annotation, TAddressSegment AddrSeg);
  // Print memory segment data
  void PrintMemsegData(TAsciiz Annotation, TAddressSegment MemSeg);
  // Print iterator state
  void PrintIterator(TAsciiz Annotation, TAddrsegIterator Rator);
  // Print duration
  void PrintDuration_Us(TAsciiz Annotation, TUint_4 Duration_Us);
  // Epitaph. Print message and went to infinite loop
  void Panic(TAsciiz);
}

/*
  2025-09-04
  2025-09-11
  2025-09-12
  2025-10-18
  2025-11-29 Panic/Epitaph
  2025-12-27
  2025-12-28
*/
