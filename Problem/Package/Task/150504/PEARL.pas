program Zerolife;
var f,g:text;
    i,t,dem:longint;
    d,c:int64;
function kt(n:int64):boolean;
var s:longint;
    sum:array[1..1458] of longint;
begin
 s:=0;
 while n>0 do
  begin
   s:=s+sqr((n mod 10));
   n:=n div 10;
  end;
 n:=s;
 fillchar(sum,sizeof(sum),0);
 while sum[n]<=1 do
  begin
   s:=0;
   while n>0 do
    begin
     s:=s+sqr((n mod 10));
     n:=n div 10;
    end;
   if s=1 then exit(false) else inc(sum[s]);
   n:=s;
  end;
 exit(true);
end;
begin
 assign(f,'PEARL.INP'); reset(f);
 assign(g,'PEARL.OUT'); rewrite(g);
 readln(f,t);
 for i:=1 to t do
  begin
   readln(f,d,c); dem:=0;
   while d<=c do
    begin
     if kt(d) then inc(dem); //else writeln(g,d);
     inc(d);
    end;
   writeln(g,dem);
  end;
 close(f);
 close(g);
end.
