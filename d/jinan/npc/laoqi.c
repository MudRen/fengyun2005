// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("鹰眼老七", ({ "laoqi" }) );
        set("long",
 "鹰眼老七本是声名显赫，雄霸一方的霸主，但因为他所辖的镖局丢了
现今太平王世子宫九押保的贡品，所以被收押大牢，本来一个很健壮
的汉子，现在却已浑身血迹，奄奄一息。\n");

        set("attitude", "heroism");
        set("title", "十二连环坞 总瓢把子");
	set("no_heal",1);
        set("cor", 26);
        set("cps", 25);
        set("kee", 5000);
        set("max_kee", 5000);
        set("eff_kee", 5);
	set("no_arrest",1);
          set("combat_exp", 1200000);

        set_skill("unarmed", 200);
        set_skill("changquan", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("move", 200);

        set_temp("apply/attack", 250);
        set_temp("apply/dodge", 220);
	set_temp("apply/parry", 220);
        set_temp("apply/damage", 50+random(100));
        set_temp("apply/armor", 100);
        set_temp("apply/move", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
"鹰眼老七挣扎着抬起头，哑声嘶叫：陆小凤啊。。你可得替我洗脱这不白之冤呀。。\n",
        }) );

        setup();
    carry_object(__DIR__"obj/bloodcloth")->wear();

}


void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
		say("鹰眼老七挣扎着抬起头看了你一眼，断断续续呻吟着：救我。。。救（ｒｅｓｃｕｅ）。。。 我。。。\n");
}

void init()
{
	::init();
	if( interactive(this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, this_player());
	}	
	add_action("do_rescue", "rescue");
}

int do_rescue(){
	object ob,money;
	if (this_player()->query("combat_exp")<1600000) {
		message_vision("鹰眼老七摇了摇头道：算了，别把你自己都给搭上。\n",this_player());
		return notify_fail("看来你还得多练几年才有可能劫狱成功。\n");
		}
	if (!objectp(ob=this_player()->query_temp("weapon")))
		return notify_fail("不用兵器看来没办法砸开枷锁。\n");
	if (ob->query("skill_type")!="hammer")
		return notify_fail("看起来只有用锤子才能砸开枷锁。\n");
//	if (sizeof(environment(this_object())->query("exits"))==0)
//		return notify_fail("要救人，至少先开个门吧？\n");				
	message_vision("$N拿起"+ob->query("name")+"，用尽全力把枷锁砸开。\n",this_player());
	message_vision("$N挣扎着站起身，长揖到地道：谢谢这位"+RANK_D->query_respect(this_player())+"救命之恩，
我先走一步，还得去请陆小凤找出真凶。。就此一别。\n",this_object());
	message_vision("$N踉踉跄跄消失在黑暗之中。。。\n",this_object());

	if (REWARD_D->riddle_check(this_player(),"浴血天牢") == 2) 
		REWARD_D->riddle_done(this_player(),"浴血天牢",50,1);

	destruct(this_object());
	return 1;
}