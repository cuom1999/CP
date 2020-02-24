var p,t:array[1..10,1..70000] of longint;
n,i,l,m,j,k,res:longint;
s,w:int64;
f,g:text;
begin
    assign(f,'dance.inp');reset(f);
    assign(g,'dance.out');rewrite(g);
    read(f,n,l,m,w);
    for i:=1 to m do
    for j:=1 to n do read(f,t[i,j]);
    for i:=1 to m do
    for j:=1 to l do read(f,p[i,j]);
    for k:=1 to n-l+1 do
    begin
        s:=0;
        for i:=1 to m do
        for j:=k to k+l-1 do s:=s+t[i,j]*p[i,j-k+1];
        if s>=w then inc(res);
    end;
    write(g,res);
    close(g);
end.