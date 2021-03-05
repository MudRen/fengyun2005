// skyforce

#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","碧空心法");
	set("type","force");
	set("effective_level",120);
	set("difficulty",200);
	set("usage/force",1);
	set("no_refund",({"henglian"}));
	set("skill_class","fugui");
	
}	

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	
	if (damage <=0)	return 0;	
	if( (me->query_temp("pfm/fg_erchuan")<=0 && me->query_temp("pfm/fg_sanchuan")<=0)
		|| me->query("class")!= "fugui"
		|| me->query_skill_mapped("iron-cloth")!= "henglian")
		return 0;
	
	if (me->query_temp("pfm/fg_erchuan")){
		me->add_temp("pfm/fg_erchuan",-1);
		data["msg"] = BBLU + WHT"$n的二串炮神功消去了$N的攻击！\n"NOR,
		data["damage"] = - damage;
		if (me->query_temp("pfm/fg_erchuan") <= 0) {
			ANNIE_D->debuff(me,"stoneskin");
		}	
	} 
	/*
	else
	{
		me->add_temp("pfm/fg_sanchuan",-1);
		data["msg"] = BBLU + WHT"$n的三串炸山轰神功消去了$N的攻击！\n"NOR,
		data["damage"] = - damage;
		if (me->query_temp("pfm/fg_sanchuan") <= 0) {
			ANNIE_D->remove_buffup( me, me->query_temp("buff_type/ironup"));
		}
	}*/
	return data;	
}


int help(object me)
{
	write(@HELP   
『碧空洗』（bikongxi）医疗气血损伤 
『丹心照』（danxinzhao）医疗心神损伤 
『清风荡』（qingfengdang)医疗精力损伤 

『欢乐英雄』（hero）
使用此心法后，在30秒内队友可模拟你下一轮的攻击（与天比
高或八方风雨）一次。每5分钟使用一次。
需160级的碧空心法。
注：队友必须使用一门enable了的武器技能，但对武器种类没
有限制。

『诱敌深入』（youdishenru）
使用此心法后，在60秒内模拟自身气血45%状态，每10分钟使用一次。
需160级的碧空心法及血战枪法190级。

HELP
    );
    return 1;
}
