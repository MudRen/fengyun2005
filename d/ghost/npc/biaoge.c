#include <ansi.h>
inherit NPC;
int tell_test();
void create()
{
        set_name("表哥", ({ "biao ge","biaoge" }) );
        set("gender", "男性");
        set("class", "ghost");
        create_family("幽灵山庄", 3, "弟子");
        set("combat_exp", 600000);
        set("long",
		"他的脸光滑而白净，就象是个刚剥了壳的鸡蛋。\n"
	);
        set("inquiry", ([
                "事" : (: tell_test :),
                "mission" :(: tell_test :),
                "一件事": (: tell_test :),
                "shi":	(: tell_test :),
                "thing":	(: tell_test :),	
        ]) );
	set("no_arrest",1);
        set_skill("move", 150);
        set_skill("dodge", 150);
        set_skill("sword", 150);
        set_skill("three-sword", 100);
        set_skill("five-steps", 100);
        set_skill("parry",100);
        map_skill("parry","three-sword");
	map_skill("dodge", "five-steps");
	map_skill("move", "five-steps");
	map_skill("sword", "three-sword");
        setup();
	carry_object(__DIR__"obj/letter");
	carry_object(__DIR__"obj/letter");
	carry_object(__DIR__"obj/cloth2")->wear();
	carry_object(__DIR__"obj/sword3")->wield();
}

void init()
{
        ::init();
	if(interactive(this_player()) && !is_fighting()) {
		call_out("greeting", 1, this_player());
	}
}

int tell_test()
{
	object		me;

	me = this_player();	
	if(me->query_temp("marks/test")) {
		me->set_temp("marks/test", 0);
		tell_object(me, YEL "\n表哥说：在下顾云飞，乃巴山剑客的弟子，家师派我来幽灵山庄卧底。"NOR);
		tell_object(me, YEL "\n我已在这里一年有多，但还不知老刀把子的真面目。"NOR);
		tell_object(me, YEL "\n我已把这一年多的所见所闻都记了下来，但一直没有机会送出去。"NOR);
		tell_object(me, YEL "\n我希望你能把这份秘函送到武当掌门石雁的手中。(answer yes/no?)\n"NOR);
		me->set_temp("marks/秘函", 1);
		add_action("do_accept", "answer");
		return 1;
	}
	return 0;
}

int greeting(object me)
{
//	object		groom;

	if( (string)me->query("family/family_name")=="幽灵山庄" ) {
		message_vision(HIY "\n$N对$n喝道：你的胆子不小！竟敢碰老刀把子的女人！\n"NOR, this_object(), me);
		message_vision(HIR "\n你就在这里等死吧！\n"NOR, this_object(), me);
	}
	else {
		message_vision(HIY "\n$N对$n喝道：你的胆子不小！竟敢碰老刀把子的女人！\n"NOR, this_object(), me);
		message_vision(HIR "\n除非你帮我做一件事，否则就在这里等死吧！\n"NOR, this_object(), me);
		me->set_temp("marks/test", 1);
	}
	return 1;
}

int do_accept(string arg)
{

	object 		me, nroom, letter;
	me = this_player();


	if(!arg || (arg != "yes" && arg != "no")) {
		tell_object(me,"answer yes/no\n");
		return 1;
	}
	if(!me->query_temp("marks/秘函")) {
		tell_object(me,"answer yes/no\n");
		return 1;
	}
	me->delete_temp("marks/秘函");

	if(arg == "yes") {
		letter = present("letter", this_object());
		if(!objectp(letter)) letter=new(__DIR__"obj/letter");
		tell_object(me, CYN"\n顾云飞笑道：太好了！这是秘函，请收好。\n"NOR);
		if (!letter->move(me))	letter->move(environment(me));
//			tell_object(me, HIY "\n顾云飞笑道：太好了！秘函我收在一个隐秘的地方，下次见面我再给你。\n"NOR);
		tell_object(me, CYN "\n现在我送你出去。\n"NOR);
		message_vision(HIR "\n表哥在椅子上按了一下，$n的脚下裂开了一个大洞，\n$n大叫了一声，掉了下去。\n"NOR, this_object(), me);
		me->set_temp("marks/顾云飞", 1);
		nroom = find_object(AREA_WUDANG"road1");
		if(!objectp(nroom)) nroom=load_object(AREA_WUDANG"road1");
		me->move(nroom);
		message_vision(HIR "\n$N从山崖上的一个小洞掉了下来。\n"NOR, me);
	}
	else {
		tell_object(me, CYN "\n顾云飞笑道：我是在试你，看来你不是奸细。\n"NOR);
		tell_object(me, CYN "\n现在我送你去见老刀把子，趁他心情好，你可以向他拜师学两手。\n"NOR);
		me->set_temp("marks/幽灵山庄", 1);
		message_vision(HIR "\n表哥在椅子上按了一下，$n的脚下裂开了一个大洞，\n$n大叫了一声，掉了下去。\n"NOR, this_object(), me);
		nroom = find_object(AREA_WUDANG"house3");
		if(!objectp(nroom)) nroom=load_object(AREA_GHOST"house3");
		me->move(nroom);
		message_vision(HIR "\n$N从神龛里滚了出来。\n"NOR, me);
	}
	return 1;
}