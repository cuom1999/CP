uses math;
var xet:array[1..2000,1..2000] of longint;
color,dau,cuoi,a:array[1..2000] of longint;
n,i,res,j,xett,l,r:longint;
s:ansistring;
f,g:text;
begin
    assign(f,'rps.inp');reset(f);
    assign(g,'rqs.out');rewrite(g);
    readln(f,n);
    for i:=1 to n do
    begin
    readln(f,s);
    for j:=1 to n do
    begin
        if s[j]='1' then xet[i,j]:=1;
        if i=j then xet[i,j]:=0;
        if xet[i,j]=1 then
        begin
            inc(cuoi[i]);
            inc(dau[j]);
        end;
    end;
    end;
    for i:=1 to n do
    if (dau[i]=0) or (cuoi[i]=0) then
    begin
        inc(r);
        a[r]:=i;
        color[i]:=1;
    end;
    l:=1;
    while (l<=r) do
    begin
        for i:=1 to n do
        if (xet[a[l],i]=1) and (color[i]=0) then
        begin
            dec(dau[i]);
            if (dau[i]=0) or (cuoi[i]=0) then
            begin
                inc(r);
                a[r]:=i;
                color[i]:=1;
            end;
        end
        else
        if (xet[i,a[l]]=1) and (color[i]=0) then
        begin
            dec(cuoi[i]);
            if (dau[i]=0) or (cuoi[i]=0) then
            begin
                inc(r);
                a[r]:=i;
                color[i]:=1;
            end;
        end;
        inc(l);
    end;
    write(g,n-r);
    close(g);
end.
