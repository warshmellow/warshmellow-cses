
Var 
  n: int64;
Begin
  readln(n);

  While True Do
    Begin
      Write(n, ' ');
      If (n = 1) Then
        break
      Else If (n Mod 2 = 0) Then
             n := n Div 2
      Else
        n := n * 3 + 1;
    End;

  writeln();
End.
