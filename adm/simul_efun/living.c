// find_living can return objects without environment();
//	This makes it very hard to look for the real NPC.
//	So I have to make some modification here.
// 在哪些情况下会用到呢? find_living(npc), npc->move(xxx)

object find_real_living(string str) {
	object ob,*ob1;
	int i;
	
	ob = efun::find_living(str);	// 保证原来的找法 :D
	
	if (!ob)	return 0;	// 找不到
		
	if (userp(ob) || clonep(ob))
		return ob;	//	99.99%	情况下，找到一个正确的
	
	if (file_name(ob))	
		ob1 = efun::children(file_name(ob));
	else
		return 0;		
	
	if (!(i=sizeof(ob1)))	return 0;
	while (i--) {
		if (clonep(ob1[i]))	return ob1[i];
	}
	
	return 0;		
}		
	