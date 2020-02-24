uses math;
const   fi='dance.inp';
        fo='dance.out';
var
n,m,l,w:longint;
p,t:array[1..100000,1..11] of longint;
Procedure inp;
var i,j:longint;
 begin
 assign(input,fi);reset(input);
 assign(output,fo);rewrite(output);
 read(n,l,m,W);
 for i:=1 to m do
 for j:=1 to n do read(t[i,j]);
 for i:=1 to m do
 for j:=1 to l do read(p[i,j]);
 close(input);
 end;
Function tinh(y:longint):boolean;
var i,j,nn:longint; tt:int64;
 begin
 tt:=0;
   nn:=y+l-1;
  if (nn>n) then exit(false);
  for i:=1 to m do
  for j:=y to nn do
  begin
  tt:=tt+t[i,j]*p[i,j-y+1];
  if tt>w then exit(true);
  end;
 exit(false);
 end;
Procedure sub1;
var i:longint; kq:int64;
 begin
 kq:=0;
  for i:=1 to n-l+1 do
  if tinh(i) then inc(kq);
  write(kq);
 end;
Procedure main;
 begin
 //if (n<=7000) and (l<=3000) then sub1 else sub2;
 sub1;
 close(output);
 end;
BEGIN
inp;
main;
END.
