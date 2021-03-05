#include <ansi.h>
inherit SMART_NPC;

void event1(object me, int count);

void create()
{
        set_name("郭嵩阳", ({ "guo songyang", "guo"}) );
        set("title","嵩阳铁剑");
        set("nickname",HIR"铮铮铁骨"NOR);
        set("gender", "男性" );
        set("age", 32);
        set("long", "
他本穿着一身的黑衣，但现在已经被折磨的只剩下几条褴褛的碎条；他本挺着高
昂的头颅，但现在已似乎没有力气抬头看你一眼。他就是兵器谱上排名第四的嵩
阳铁剑，郭嵩阳。遍体鳞伤，披头散发，衣不蔽体，被四根粗如腕臂的铁链穿过
四肢骨筋，牢牢的吊在当中。\n");
	set("combat_exp", 5000000);
        set_skill("sword", 100);
	set_skill("dodge", 40);
	set_temp("condition_type",RED "<锁铐中>" NOR);
	
	auto_npc_setup("liaoyin",200,200,0,"/obj/weapon/","fighter_w","huidashi",1);
	set_skill("perception",200);
	set_skill("sword",200);
	set_skill("sky-sword",140);
	map_skill("sword","sky-sword");
	map_skill("parry","sky-sword");
	set("NO_KILL","屠杀毫无还手之力之人，情何以堪？\n");
	setup();
}



void	die(){
	object cloth;
	object me, owner;
        if (this_object()->query("can_die")) {
        	::die();
        	return;
        }
        if (this_object()->query_temp("in_talk"))
        	return;
        	
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        set("NO_KILL","郭嵩阳已经奄奄一息了，还是让他说完最后的话吧。\n");
	if (!me) ::die();
	me->start_busy(10);
	event1(me, 0);
	set_temp("in_talk",1);
	
}

string *event1_msg=	({
	
	HIR"\n郭嵩阳大口大口的吐着血，手中铁剑支地，鲜血顺着剑尖一滴滴淌到地上。\n"NOR,
	
	HIC"郭嵩阳眼中的异彩逐渐消失，代之而现的是一种无法形容的神采和傲气。\n"NOR,
	
	HIC"郭嵩阳挣扎着昂起头，凄然一笑：谢。。谢你，郭嵩阳。。。终于又是郭嵩阳，
天下第四的郭嵩阳了。 \n"NOR,

	HIR"郭嵩阳突然长剑切腹，颤抖着从鲜血淋漓的小腹里拿出一块满是鲜血的木鼎。 \n"NOR,

    	HIR"郭嵩阳嘿然一笑，断断续续道：上官。。怎么也不会想到，手下败将郭嵩阳。。。
此行金钱终有斩获，苍生乱不能大规模炼制，因为。。。药引无间木被我从赤虚的
贼窟里盗得。。。嘿。。。嘿。。。 \n"NOR,
    
	HIC"\n郭嵩阳挣扎着将满是血污的无间木塞到你手中，释然一笑，阖目而逝。\n\n\n"NOR,

//    	HIC"\n郭嵩阳挣扎着将满是血污的无间木塞到你手中，又强自说道：此恩今生难报，我将祖
//传铁剑藏于长白天梯之下，你可取而用之。说罢释然一笑，阖目而逝。\n\n\n"NOR,
    	
});


void event1(object me, int count)
{
	object wood;
	mapping data;
	
	if ( !me || environment(me)!= environment(this_object())) 	return;
		
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		
		wood = new(__DIR__"obj/jq2-wood");
		
		if (wood) {
			wood->set("owner",me);
			wood ->move(me);
		}

		REWARD_D->riddle_set(me,"再闯金钱",3);		

		me->stop_busy();
		set("can_die",1);
		delete_temp("in_talk");
		die();
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}


void 	unconcious(){
	die();
}