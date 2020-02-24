program Zerolife;
var f,g:text;
    n,m,l,w,i,j,dem:longint;
    a,t:array[1..10,1..7000] of longint;
function kt(d,c:longint):boolean;
var i,j,k:longint;
    s:int64;
begin
 s:=0;
 for i:=1 to m do
  begin
   k:=0;
   for j:=d to c do
    begin
     inc(k);
     s:=s+a[i,j]*t[i,k];
    end;
  end;
 if s>w then exit(true) else exit(false);
end;
begin
 assign(f,'DANCE.INP'); reset(f);
 assign(g,'DANCE.OUT'); rewrite(g);
 readln(f,n,l,m,w);
 for i:=1 to m do
  begin
   for j:=1 to n do read(f,a[i,j]);
   readln(f);
  end;
 for i:=1 to m do
  begin
   for j:=1 to l do read(f,t[i,j]);
   readln(f);
  end;
 for i:=1 to n-i+1 do
  if kt(i,i+l-1) then inc(dem);
 writeln(g,dem);
 close(f);
 close(g);
end.