// [me_DebugPrints] test

/*
  Author: Martin Eden
  Last mod.: 2025-09-20
*/

#include <me_DebugPrints.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_Duration.h>

#include <me_Console.h>
#include <me_WorkmemTools.h>

void TestPrints()
{
  using me_DebugPrints::Print;

  TUnit Unit;
  TAddress Address;
  TBool Bool;

  Unit = 10;
  Address = 1000;
  Bool = true;

  Print("Unit", Unit);
  Print("Address", Address);
  Print("Bool", Bool);
  Console.EndLine();
}

void TestAddrsegPrint()
{
  using me_DebugPrints::PrintAddrseg;

  TAddressSegment AddrSeg;

  AddrSeg = { .Addr = 100, .Size = 3 };

  PrintAddrseg("Address segment", AddrSeg);
  Console.EndLine();
}

void TestMemsegPrint()
{
  using me_DebugPrints::PrintMemsegData;

  TAddressSegment MemSeg;

  MemSeg = me_WorkmemTools::FromAsciiz("DATA");

  PrintMemsegData("Memory data", MemSeg);
  Console.EndLine();
}

void TestIteratorPrint()
{
  using me_DebugPrints::PrintIterator;

  TAddrsegIterator Rator;
  TAddressSegment AddrSeg;

  AddrSeg = { .Addr = 100, .Size = 3 };
  Rator.Init(AddrSeg);

  Rator.AdvanceAddr();
  Rator.AdvanceAddr();
  Rator.AdvanceAddr();
  Rator.AdvanceAddr();

  PrintIterator("Iterator", Rator);
}

void TestDurationPrint()
{
  using me_DebugPrints::PrintDuration;

  me_Duration::TDuration Duration;

  Duration = { .KiloS = 0, .S = 0, .MilliS = 15, .MicroS = 712 };

  PrintDuration("Duration", Duration);
  Console.EndLine();
}

void RunTests()
{
  TestPrints();
  TestAddrsegPrint();
  TestMemsegPrint();
  TestIteratorPrint();
  TestDurationPrint();
}

void setup()
{
  Console.Init();

  Console.Print("( [me_DebugPrints] test");
  Console.Indent();

  RunTests();

  Console.Unindent();
  Console.Print(") Done");
}

void loop()
{
}

/*
  2025-09-04
  2025-09-12
*/
