// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("湛蓝", ({ "zhan lan", "lan","girl" }) );
	set("class","moon");
	set("gender", "女性" );
	set("age", 19);
	set("per", 36);
	set("int", 40);
	set("str", 24);
	set("score",-10000);
   	create_family("/", 3, "");
	set("title",CYN"梦落淡烟疏雨中"NOR);
	set("attitude", "friendly");
	set("long","一个秀发如云，披散及腰的少女，正抱膝坐在亭栏之上，一对星眸凝望
着远方。山风吹过，她披着的薄纱翻飞而起，露出纱下凝脂般的身体，
修长圆润的双腿，纤柔合握的腰肢．．．\n");
	set("chat_chance", 1);
	set("chat_msg", ({
		"湛蓝低声自语道：千万恨，恨极在天涯。山月不知心里事，水风空落眼前花．．．\n",
		"湛蓝叹道：英雄末路，美人迟暮，有情人终成怨偶．．．\n",
		"湛蓝痴痴的望着远方，轻声吐字：生当复来归，死当长相思．．．\n",
	}) );

	set("inquiry",([
		"李坏": 	"唉．．．\n",
       	"月神": 	"荆王梦罢已春归，陌上花随暮雨飞．．．\n",
    	]) );

	set("no_arrest",1);
	set("skill_public",1);

	set_skill("spells",150);
	set_skill("heart-listening",200);
	map_skill("spells","heart-listening");

	set("NO_KILL","对一介弱女子你也下得了手？\n");

	setup();

	carry_object(__DIR__"obj/longskirt")->wear();
	carry_object(__DIR__"obj/jasmine")->wear();
	carry_object(__DIR__"obj/shoes")->wear();

}

void init()
{
	add_action("do_rape","rape");
}

int do_rape() // 去死吧!!!! ><"
{
	object me;
	me = this_player();
	message_vision(HIM"\n$N如野兽般的扑向$n，向$n的衣服撕去．．．\n\n"NOR,me,this_object());
	message_vision(HIB"$n偏过头，厌恶的看了$N一眼，伸出右手在空中微微一划，临虚书写了一个符文。
浅蓝色的微芒在空气中一闪即没，$N只觉得一道莫大的力量推来，跌跌撞撞的向山崖外摔去。\n\n"NOR,me,this_object());
	me->add_temp("block_msg/all",1);
	me->move("/obj/void");
	me->set_temp("last_damage_from","妄行轻薄，不慎摔下山崖变成肉泥了。");
	me->die();	
	if (me->query_temp("block_msg/all")>=1)
	    me->add_temp("block_msg/all", -1);
	ccommand("heng");
	ccommand("hug zhan lan");
	return 1;
}




int recognize_apprentice(object ob)
{	
	object me = ob;

	if (ob->query("class") == "moon" 
		&& ob->query_temp("annie/seablue")
		&& ob->query_skill("chillblade",1)>=190 )
		return 1;

	if ( ob->query("class") == "moon"
		&& ob->query_skill("chillblade",1)>=190 )
	{
		message_vision(CYN"\n$n回头顾了$N一眼，柔柔一笑。\n$n拍了拍身边的亭栏。\n"NOR,ob,this_object());
		ob->set_temp("annie/seablue",1);
		command ("say 既是薛姐姐的门下，不妨坐过来陪我说说闲话。");
		return 1;
	}

	return notify_fail("湛蓝别过头去，对你理也不理。\n");

}
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

