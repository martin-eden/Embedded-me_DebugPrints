// Debug prints implementation

/*
  Author: Martin Eden
  Last mod.: 2025-09-11
*/

#include <me_DebugPrints.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

#include <me_Console.h>
#include <me_StreamsCollection.h>

using namespace me_DebugPrints;

/*
  Print unit
*/
void me_DebugPrints::Print(
  TAsciiz Annotation,
  TUnit Unit
)
{
  Console.Write(Annotation);
  Console.Print(Unit);
}

/*
  Print address
*/
void me_DebugPrints::Print(
  TAsciiz Annotation,
  TAddress Address
)
{
  Console.Write(Annotation);
  Console.Print(Address);
}

/*
  Print boolean
*/
void me_DebugPrints::Print(
  TAsciiz Annotation,
  TBool Bool
)
{
  Console.Write(Annotation);
  Console.Print(Bool);
}

/*
  Print address segment span
*/
void me_DebugPrints::PrintAddrseg(
  TAsciiz Annotation,
  TAddressSegment AddrSeg
)
{
  Console.Write(Annotation);
  Console.Write(" ( ");
  Print("Addr", AddrSeg.Addr);
  Print("Size", AddrSeg.Size);
  Console.Write(")");
}

/*
  Print work memory segment span and data
*/
void me_DebugPrints::PrintMemseg(
  TAsciiz Annotation,
  TAddressSegment MemSeg
)
{
  me_StreamsCollection::TWorkmemInputStream MemStream;
  TUnit Unit;

  PrintAddrseg(Annotation, MemSeg);
  Console.Write(" ");
  Console.Write("Data");
  Console.Write(" (");

  MemStream.Init(MemSeg);
  while (MemStream.Read(&Unit))
    Console.Print(Unit);

  Console.Write(")");
}

/*
  Print iterator state
*/
void me_DebugPrints::PrintIterator(
  TAsciiz Annotation,
  TAddrsegIterator Rator
)
{
  Console.Write(Annotation);
  Console.Write(" ( ");
  Print("Addr", Rator.GetAddr());
  Print("IsDone", Rator.IsDone());
  Console.Write(")");
}

/*
  2025-09-04
*/
