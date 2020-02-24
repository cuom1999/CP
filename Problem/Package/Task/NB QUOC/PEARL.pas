const fi='PEARL.inp';
      fo='PEARL.out';
var ff,s:array[1..1458] of longint;
    n:longint;
    f:array[1..19,0..1457,boolean] of int64;
    t:string;
Function cong(x:int64):longint;
var s:longint;
   begin
   s:=0;
   repeat
   s:=s+sqr(x mod 10);
   x:=x div 10;
   until x=0;
   Exit(s);
   End;
function dq(i:longint):longint;
   begin
   if ff[i]=2 then ff[i]:=1;
   if(ff[i]=0)or(ff[i]=1) then exit(ff[i]);
   ff[i]:=2;
   ff[i]:=dq(cong(i));
   exit(ff[i]);
   End;
Function tinh(i,j:longint; ok:boolean):int64;
var l,tg,tg1:longint;
    ss:int64;
    tg2:boolean;
   begin
   if i=n then
      begin
      if trunc(sqrt(j))<>sqrt(j) then begin f[i,j,ok]:=0; exit(0); End;
      if ok then begin f[i,j,ok]:=1; exit(1); End;
      if trunc(sqrt(j))<=ord(t[i])-48 then begin f[i,j,ok]:=1; exit(1); End
      else begin f[i,j,ok]:=0; exit(0); End;
      End;
   if f[i,j,ok]>-1 then exit(f[i,j,ok]);
   ss:=0; tg:=ord(t[i])-48; tg1:=j-(n-i)*81;
   for l:=0 to 9 do
   if ((ok)or(l<=tg))and(l*l>=tg1)and(j>=l*l) then
       begin
       if ok then tg2:=true
       else
          begin
          if l<tg then tg2:=true
          else tg2:=false;
          End;
       ss:=ss+tinh(i+1,j-l*l,tg2);
       End;
   f[i,j,ok]:=ss;
   exit(ss);
   End;
Procedure main;
var i,m,q,l:longint;
    u,v,su,sv:int64;
   begin
   fillchar(ff,sizeof(ff),255);
   ff[1]:=0; n:=1458;
   for i:=2 to n do
   ff[i]:=dq(i);
   m:=0;
   for i:=1 to n do
   if ff[i]=0 then begin inc(m); s[m]:=i; End;
   assign(input,fi); reset(input);
   assign(output,fo); rewrite(output);
   readln(q);
   for l:=1 to q do
      begin
      read(u,v); dec(u);
      str(u,t); n:=length(t); su:=0;
      fillchar(f,sizeof(f),255);
      if u<>0 then for i:=1 to m do su:=su+tinh(1,s[i],false);
      sv:=0; str(v,t); n:=length(t);
      fillchar(f,sizeof(f),255);
      for i:=1 to m do
      sv:=sv+tinh(1,s[i],false);
      writeln(v-u-sv+su);
      End;
   close(input);close(output);
   End;
begin
main;
End.
