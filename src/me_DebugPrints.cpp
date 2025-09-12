// Debug prints implementation

/*
  Author: Martin Eden
  Last mod.: 2025-09-12
*/

#include <me_DebugPrints.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_Timestamp.h>

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
  Console.Write(" (");
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
  Console.Write(" ( ");
  Print("Addr", Rator.GetAddr());
  Print("IsDone", Rator.IsDone());
  Console.Write(")");

  Console.EndLine();
}

/*
  Print time duration
*/
void me_DebugPrints::PrintDuration(
  me_Timestamp::TTimestamp Duration
)
{
  TBool IsStarted;

  Console.Write("(");

  IsStarted = false;

  if (Duration.KiloS != 0)
    IsStarted = true;
  if (IsStarted)
    Console.Print(Duration.KiloS);

  if (Duration.S != 0)
    IsStarted = true;
  if (IsStarted)
    Console.Print(Duration.S);

  if (Duration.MilliS != 0)
    IsStarted = true;
  if (IsStarted)
    Console.Print(Duration.MilliS);

  if (Duration.MicroS != 0)
    IsStarted = true;
  if (IsStarted)
    Console.Print(Duration.MicroS);

  Console.Write(")");
  Console.EndLine();
}

/*
  2025-09-04
  2025-09-11
  2025-09-12
*/
