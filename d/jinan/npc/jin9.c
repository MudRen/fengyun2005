// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("金九龄", ({ "jin" }) );
        set("long",
                "金九龄本是六扇门下第一神捕，高贵富有，但实为连犯数件大案的绣花大盗。
陆小凤历尽艰辛方才将其绳之于法，现被关押在济南天牢中。\n");

        set("attitude", "heroism");
        set("title", "绣花大盗");
		set("no_heal",1);
        set("cor", 26);
        set("cps", 25);
        set("kee", 2000);
        set("max_kee", 2000);
        set("eff_kee", 500);
		set("no_arrest",1);
        set("combat_exp", 1000000+random(4000000));

        set_skill("unarmed", 70+random(500));
        set_skill("dagger", 300);
        set_skill("parry", 70+random(500));
        set_skill("dodge", 70+random(500));
        set_skill("move", 100+random(500));

        set_temp("apply/attack", 200);
        set_temp("apply/dodge", 200);
		set_temp("apply/parry", 200);
        set_temp("apply/damage", 100+random(200));
        set_temp("apply/armor", 10);
        set_temp("apply/move", 10);
        set("chat_chance", 1);
        set("chat_msg", ({
"金九龄长叹一声黯然道：我实在是低估了陆小凤那厮。。。\n",
        }) );

        setup();
    	carry_object(__DIR__"obj/xiuhuazhen")->wield();
    	carry_object(__DIR__"obj/bloodcloth")->wear();

}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
		say( "金九龄挣扎着抬起头看了你一眼，断断续续呻吟着：救我。。。救（ｒｅｓｃｕｅ）。。。 我。。。\n");
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
	if (!objectp(ob=this_player()->query_temp("weapon")))
		return notify_fail("不用兵器看来没办法砸开枷锁。\n");
	if (ob->query("skill_type")!="hammer")
		return notify_fail("看起来只有用锤子才能砸开枷锁。\n");
	if (sizeof(environment(this_object())->query("exits"))==0)
		return notify_fail("要救人，至少先开个门吧？\n");
	if (this_player()->query("str")<21)
		return notify_fail("你用尽全力砸向枷锁，枷锁却纹丝未损。\n");			
	
	message_vision("$N拿起"+ob->query("name")+"，用尽全力把枷锁砸开。\n",this_player());
	message_vision("$N理了理散发，仰面大笑：哈。。哈。。陆小凤，我会找你算清这笔帐的！\n",this_object());
	
	if (this_player()->query("marks/prison_break")
		|| this_player()->query("combat_exp")<1600000) {
		message_vision("$N挥了挥衣袖，大笑中踪影皆无。\n",this_object());
		} else {
		this_player()->set("marks/prison_break",1);
		message_vision("$N低着眼睛扫了$n一眼：也亏得你来救我，这几张银票给你算做酬谢。\n",this_object(),this_player());
		message_vision("$N挥了挥衣袖，大笑中踪影皆无。\n",this_object());
		money=new(THCASH_OB);
		money->set("illegal",1);
		money->move(this_player());
		money=new(THCASH_OB);
		money->set("illegal",1);
		money->move(this_player());
		money=new(THCASH_OB);
		money->set("illegal",1);
		money->move(this_player());
		}
	destruct(this_object());
	return 1;
}