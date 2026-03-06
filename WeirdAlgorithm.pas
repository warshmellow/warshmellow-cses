
Type 
  TBoolArray = Array Of boolean;

Var 
  n: int64;
  seen: TBoolArray;
  i, x: int64;
Begin
  readln(n);
  SetLength(seen, n + 1);

  For i := 1 To n - 1 Do
    Begin
      read(x);
      seen[x] := True;
    End;

  For i := 1 To n Do
    If (Not seen[i]) Then
      writeln(i);
End.
