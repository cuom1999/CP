//calc a*b/c (a<c);

II div_operation(ll a, ll b, ll c){
	if (b==0) return II(0,0);
	II q=div_operation(a,b/2,c);
	if (b%2==0){
		return II(2*q.first+(2*q.second)/c,(2*q.second)%c);
	}
	return II(2*q.first+(2*q.second+a)/c,(2*q.second+a)%c);
}

ll div(ll a, ll b, ll c) {
	return div_operation(a,b,c).first;
}
