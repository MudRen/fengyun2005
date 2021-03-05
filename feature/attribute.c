// attribute.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 

#include <dbase.h>
int query_str() {
	return (int)query("str") 
			+ (int)query("force_factor")/3 
			+ (int)query_temp("apply/strength")
			+ (int)query("attr_apply/strength");
}

int query_cor() {
	return (int)query("cor") 
			+ (int)query("bellicosity") / 1000
			+ (int)query_temp("apply/courage")
			+ (int)query("attr_apply/courage");
}

int query_int() {
	return (int)query("int")
			+ (int)query_temp("apply/intelligence")
			+ (int)query("attr_apply/intelligence");
}

int query_spi() {
	return (int)query("spi")
			+ (int)query_temp("apply/spirituality")
			+ (int)query("attr_apply/spirituality");
}

int query_cps() {
	return (int)query("cps")
//			+ (int)query("force_factor") / 5
			+ (int)query_temp("apply/composure")
			+ (int)query("attr_apply/composure");
}

int query_per() {
	return (int)query("per")
			+ query_temp("apply/personality")
			+ query("attr_apply/personality");
}

int query_con() {
	return (int)query("con")
			+ (int)query_temp("apply/constitution")
			+ (int)query("attr_apply/constitution");
}

int query_kar() {
	return (int)query("kar")
			+ (int)query_temp("apply/karma")
			+ (int)query("attr_apply/karma");
}

int query_agi() {
	return (int)query("agi")
			+ (int)query_temp("apply/agility")
			+ (int)query("attr_apply/agility");
}

int query_dur() {
	return (int)query("dur")
			+ (int)query_temp("apply/durability")
			+ (int)query("attr_apply/durability");
}

int query_fle() {
	return (int)query("fle")
			+ (int)query_temp("apply/flexibility")
			+ (int)query("attr_apply/flexibility");
}

int query_tol() {
	return (int)query("tol")
			+ (int)query_temp("apply/tolerance")
			+ (int)query("attr_apply/tolerance");
}

int query_level(){
	return (int)query("level");
}
