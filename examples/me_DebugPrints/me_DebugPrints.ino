// [me_DebugPrints] test

/*
  Author: Martin Eden
  Last mod.: 2025-09-04
*/

#include <me_DebugPrints.h>

#include <me_BaseTypes.h>
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

  PrintAddrseg("AddrSeg", AddrSeg);
  Console.EndLine();
}

void TestMemsegPrint()
{
  using me_DebugPrints::PrintMemseg;

  TAddressSegment MemSeg;

  MemSeg = me_WorkmemTools::FromAsciiz("DATA");

  PrintMemseg("MemSeg", MemSeg);
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

void RunTests()
{
  TestPrints();
  TestAddrsegPrint();
  TestMemsegPrint();
  TestIteratorPrint();
}

void setup()
{
  Console.Init();

  Console.Print("( [me_DebugPrints] test");

  RunTests();

  Console.Print(") Done");
}

void loop()
{
}

/*
  2025-09-04
*/
