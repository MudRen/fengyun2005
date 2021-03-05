#include <ansi.h>
inherit NPC;

void create()
{
        set_name("叶灵", ({ "ye ling", "ye", "ling" }) );
        set("gender", "女性");
        set("per", 30);
        set("age", 17);
        set("class", "ghost");
        create_family("幽灵山庄", 3, "弟子");
        set("combat_exp", 100000);
        set("long",
		"一个身穿红色衣服，一双乌溜溜的大眼睛望着你。\n"
	);
	set("no_arrest",1);
        set_skill("move", 50);
        set_skill("dodge", 150);
        set_skill("unarmed", 100);
        set_skill("taiji", 50);
        set_skill("five-steps", 80);
	map_skill("dodge", "five-steps");
	map_skill("move", "five-steps");
	map_skill("unarmed", "taiji");
        setup();
	carry_object(__DIR__"obj/cloth2")->wear();
}

void init()
{
	object		me;

        ::init();
        me = this_player();
        if( interactive(me) && !is_fighting() && !me->is_ghost() ) {
                call_out("greeting", 1, me);
        }
}

int greeting(object me)
{
	object		groom;
	
	if (!me || environment(me) != environment(this_object()))	return 1;
		
	if( (string)me->query("family/family_name")=="幽灵山庄" ) {
		message_vision(HIY "\n$N对$n喝道：老刀把子告诉过你，不许进我的房间！\n"NOR, this_object(), me);
		groom = find_object(AREA_GHOST"ghost");
		if(!objectp(groom)) groom = load_object(AREA_GHOST"ghost");
		me->move(groom);
		message_vision(HIY "\n$N被$n踢了出来！\n"NOR, me,this_object());
	}
	else {
		if((int)me->query("per")<27 || (string)me->query("gender")!="男性") {
			message_vision(HIY "\n$N对$n喝道：你是谁？竟敢乱闯我的房间！\n"NOR, this_object(), me);
			groom = find_object(AREA_GHOST"ghost");
			if(!objectp(groom)) groom = load_object(AREA_GHOST"ghost");
			me->move(groom);
			message_vision(HIY "\n$N被$n踢了出来！\n"NOR, me,this_object());
		}
		else {
			message_vision(HIY "\n$N上下打量了对$n几眼，说道：这里以后就是你的房间了，没事别乱跑！\n"NOR, this_object(), me);
		}
	}
	return 1;
}
