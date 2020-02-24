const fi='RPS.inp';
      fo='RPS.out';
var a:array[1..2000,1..2000] of boolean;
    n,kq:longint;
    f:array[1..20000] of boolean;
    s,t:array[1..20000] of longint;
Procedure enter;
var i,j:longint;
    u:char;
   begin
   assign(input,fi); reset(input);
   readln(n);
   for i:=1 to n do
     begin
     for j:=1 to n do
        begin
        read(u);
        if u='0' then a[i,j]:=false else a[i,j]:=true;
        End;
     readln;
     End;
   close(input);
   End;
Procedure main;
var i,j,l,top1,top2:longint;
   begin
   if n<=200 then
      begin
      kq:=0;
      for i:=1 to n do f[i]:=true;
      for i:=1 to n do
      if f[i] then
         begin
         for j:=1 to n do
         if j<>i then
            begin
            if a[i,j] then
               begin
               for l:=1 to n do
               if (l<>i)and(l<>j)and(a[j,l])and(a[l,i]) then
                   begin
                   if f[i] then inc(kq);
                   if f[j] then inc(kq);
                   if f[l] then inc(kq);
                   f[i]:=false; f[j]:=false; f[l]:=false;
                   End;
               End
            else
               begin
               for l:=1 to n do
               if (l<>i)and(l<>j)and(a[l,j])and(a[i,l]) then
                   begin
                   if f[i] then inc(kq);
                   if f[j] then inc(kq);
                   if f[l] then inc(kq);
                   f[i]:=false; f[j]:=false; f[l]:=false;
                   End;
               End
            End;
         End;
      exit;
      End;
   for i:=1 to n do f[i]:=true;
   for i:=1 to n do
      begin
      top1:=0; top2:=0;
      for j:=i+1 to n do
        begin
        if a[i,j] then begin inc(top1); s[top1]:=j; End
        else begin inc(top2); t[top2]:=j; End;
        End;
      for j:=1 to top1 do
      for l:=1 to top2 do
      if a[s[j],t[l]] then begin f[i]:=false; f[s[j]]:=false; f[t[l]]:=false; End;
      End;
   kq:=n;
   for i:=1 to n do
   if f[i] then dec(kq);
   End;
procedure print;
   begin
   assign(output,fo); rewrite(output);
   write(kq);
   close(output);
   End;
Begin
enter;
main;
print;
End.
