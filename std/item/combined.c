// combined.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
//	add query_volumn() to get the original amount of combined items.
//			--- 12/19/2002 by silencer


#include <dbase.h>
#include <name.h>

inherit ITEM;

nosave int amount;

void create() {
	if(clonep(this_object())) {
		destruct(this_object());
		return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
	}
}

int query_amount() { 
	return amount; 
}

int query_volumn() {
	return query("volumn")? query("volumn") : 1;
}

void set_amount(int v) {
	if(v <=0)  {
		destruct(this_object());
	} else {
		amount = v;
		this_object()->set_weight(v * (int)query("base_weight"));
		this_object()->set("value", v * (int)query("base_value"));
	}
}

void add_amount(int v) { 
	set_amount(amount+v); 
}

string short() {
	return chinese_number(query_amount()) + query("base_unit")
		+ ::short();
}

varargs int move(mixed dest, int silent) {
	object *inv;
	string file;
	int i, total;
	
	if(::move(dest, silent) ) {
		if(this_object()->query("item_damaged")) {
			return 1;	
		}
		file = base_name(this_object());
		inv = all_inventory(environment());
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]==this_object() || inv[i]->query("item_damaged")) {
				continue;
			}
			if(base_name(inv[i])==file) {
				total = (int)inv[i]->query_amount();
				destruct(inv[i]);
				break;
			}
		}
		add_amount(total);
		return 1;
	}
	return 0;
}