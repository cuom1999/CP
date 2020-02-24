program Zerolife;
var  f,g:text;
     n,m,dem,i:longint;
     d,c,tro,ke,color:array[1..100000] of longint;
procedure khoitao;
var i,j,u,v:longint;
    t:char;
begin
 readln(f,n);
 for i:=1 to n do
  begin
   for j:=1 to n do
    begin
     read(f,t);
     if t='1' then
      begin
       inc(m);
       d[m]:=i; c[m]:=j;
      end;
    end;
   readln(f);
  end;
 for i:=1 to m do inc(tro[d[i]]);
 v:=1;
 for i:=1 to n do
  begin
   u:=tro[i];
   tro[i]:=v;
   v:=u+v;
  end; tro[n+1]:=v;
 for i:=1 to m do
  begin
   u:=d[i]; v:=c[i];
   ke[tro[u]]:=v; inc(tro[u]);
  end;
 for i:=n downto 2 do tro[i]:=tro[i-1]; tro[1]:=1;
end;
procedure xl(u:longint);
var i,j,t,v,k:longint;
begin
 for i:=tro[u] to tro[u+1]-1 do
  begin
   v:=ke[i];
   for j:=tro[v] to tro[v+1]-1 do
    begin
     k:=ke[j];
     for t:=tro[k] to tro[k+1]-1 do
      if ke[t]=u then
       begin
        color[u]:=1;
        color[v]:=1;
        color[ke[t]]:=1;
       end;
    end;
  end;
end;
begin
 assign(f,'RPS.INP'); reset(f);
 assign(g,'RPS.OUT'); rewrite(g);
 khoitao;
 for i:=1 to n do
  if color[i]=0 then xl(i);
 for i:=1 to n do if color[i]=1 then inc(dem);
 writeln(g,dem);
 close(f);
 close(g);
end.