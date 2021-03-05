// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int jice();

void create()
{
	object weapon;
        set_name("晦气大师", ({ "hui qi", "huiqi" }) );
        set("gender", "男性" );
        set("class", "bonze");
	set("title","兴国禅寺晦字辈大师");
	set("long","
晦气大师自幼便在兴国禅寺出家，论起辈分还是主持兴国大师的师叔，只是
他不爱管寺里的事儿，整天以研读佛经为乐。\n");
        set("age", 89);
        set("combat_exp", 6000000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );

		set("death_msg",CYN"\n$N大叫道：你～～～～～～～～！\n"NOR);

            set("inquiry",([
 		"殷正廉"  : (: jice :),
           ]) );
		setup();

        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
    	auto_npc_setup("ouyang",220,200,0,"/obj/weapon/","fighter_w","thunderwhip",1);
}





int jice()
{
	object me;
	me = this_player();
	if (me->is_fighting())
	{
		message_vision("$N脸色一变，强作镇定道：老衲不问世事久矣，这位施主还是去向别人打听罢。\n",this_object(),me);
		return 1;
	}
	if(REWARD_D->riddle_check(me,"探流追源") != 5)
	{
		message_vision("$N脸色一变，强作镇定道：老衲不问世事久矣，这位施主还是去向别人打听罢。\n",this_object(),me);
		return 1;
	}

	if (query("doing"))
	{
		message_vision("$N脸色一变，强作镇定道：老衲不问世事久矣，这位施主还是去向别人打听罢。\n",this_object(),me);
		return 1;
	}

	message_vision(WHT"$N的脸色骤变得灰白如土，频频冷颤。\n"NOR,this_object(),me);
	message_vision(CYN"$N惊疑道：你，你是谁？你怎生知道此事？\n"NOR,this_object(),me);

	tell_object(me,HIR"\n看来那灰衣人不曾骗你，晦气大师果然有问题，动手罢！\n"NOR);

	set("doing",1);

	REWARD_D->riddle_set(me,"探流追源",6);

	return 1;
}

void die()
{
	object me = query_temp("last_damage_from");
	if(!me || REWARD_D->riddle_check(me,"探流追源") != 6)
	{
		::die();
		return ;
	}


	message_vision(CYN"$N挣扎道：正廉他不想认我这个老父，因此派你来下手么．．\n"NOR,this_object(),me);
	message_vision(CYN"$N呕出一口鲜血，惨惨而笑：这样也好，我就不会．．再碍着正廉的前程了．．\n"NOR,this_object(),me);
	message_vision(CYN"$N五指抓在地上，慢慢道：我佛．．．慈．．悲．．．\n"NOR,this_object(),me);
	REWARD_D->riddle_set(me,"探流追源",7);


	tell_object(me,HIR"\n此事峰回路转，竟然又有蹊跷，现在也只能回明霞山，找灰衣人问个清楚。\n"NOR);
	::die();
	return ;
}
