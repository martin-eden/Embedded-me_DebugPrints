// Debug prints implementation

/*
  Author: Martin Eden
  Last mod.: 2025-12-26
*/

#include <me_DebugPrints.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_Duration.h>

#include <me_Console.h>
#include <me_StreamsCollection.h>

using namespace me_DebugPrints;

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
  Print uint_4
*/
void me_DebugPrints::Print(
  TAsciiz Annotation,
  TUint_4 Uint_4
)
{
  Console.Write(Annotation);
  Console.Print(Uint_4);
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
  Console.Write("(");
  Print("Addr", AddrSeg.Addr);
  Print("Size", AddrSeg.Size);
  Console.Write(")");
  Console.EndLine();
}

/*
  Print work memory segment data
*/
void me_DebugPrints::PrintMemsegData(
  TAsciiz Annotation,
  TAddressSegment MemSeg
)
{
  me_StreamsCollection::TWorkmemInputStream MemStream;
  TUnit Unit;

  MemStream.Init(MemSeg);
  Console.Write(Annotation);
  Console.Write("(");
  while (MemStream.Read(&Unit))
    Console.Print(Unit);
  Console.Write(")");
  Console.EndLine();
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
  Console.Write("(");
  Print("Addr", Rator.GetAddr());
  Print("IsDone", Rator.IsDone());
  Console.Write(")");

  Console.EndLine();
}

/*
  Print time duration
*/
void me_DebugPrints::PrintDuration(
  me_Duration::TDuration Duration
)
{
  IOutputStream * OutStream;

  OutStream = Console.GetOutputStream();

  Console.Write("(");
  me_Duration::Write(Duration, OutStream);
  Console.Write(")");
}

/*
  Print message and halt
*/
void me_DebugPrints::Panic(
  TAsciiz Epitaph
)
{
  Console.EndLine();
  Console.Print(Epitaph);
  Console.Print("∎");
  while (true) ;
}

/*
  2025-09-04
  2025-09-11
  2025-09-12
  2025-09-14
  2025-09-19
  2025-11-29
*/
