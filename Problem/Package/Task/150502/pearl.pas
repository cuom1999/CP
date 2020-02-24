var l,r,res,i,t:int64;
//a:array[0..10000] of longint;
lol:longint;
f,g:text;
procedure ktra(x:int64);
var s,d,xx:int64;
begin
    d:=0;
    {if a[x]=1 then
    begin
        inc(res);
        writeln(g,x);
        exit;
    end;}
    while (x<>1) and (d<=7) do
    begin
        s:=0;
        while x>0 do
        begin
            xx:=x mod 10;
            s:=s+sqr(xx);
            x:=x div 10;
        end;
        x:=s;
        inc(d);
       { if a[x]=1 then
        begin
            x:=1;
            break;
        end;
        if d=1 then t:=s;    }
    end;
    if x=1 then
    begin
        inc(res);
        //writeln(g,i);
        //a[t]:=1;
       // writeln(g,i);
    end;
end;
begin
    assign(f,'pearl.inp');reset(f);
    assign(g,'pearl.out');rewrite(g);
    read(f,t);
    for lol:=1 to t do
    begin
    read(f,l,r);
    //ktra(2942002);
    i:=l;
    while (i<=r) do
    begin
        ktra(i);
        inc(i);
    end;
    writeln(g,(r-l+1)-res);
    end;
    close(g);
end.
