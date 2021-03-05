// XXDER
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("阿福" , ({ "afu", "a fu" }) );
	set("long", "一个躬腰驼背的老人，没人知道他姓什么，大家都叫他阿福。\n");
	set("attitude", "friendly");
	set("age", 58);
        set("gender", "男性" );
	set("combat_exp", 50000);
	set_skill("dodge", 20+random(20));
	set_skill("unarmed",50+random(50));
	set("force_factor",50);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 10, ob);
	}
}

void greeting(object ob)
{
   if( !ob || environment(ob) != environment() ) return;
   switch( random(3) ) {
      case 0:
         message_vision("$N神秘地说道：＂你知不知道这花园可以通神仙住的地方? ＂\n",this_object(),ob);
         break;
      case 1:
         message_vision("$N叹了口气说道：＂仙女什么时候会再来呢? ＂ \n", this_object(),ob);
         break;
      case 2:
         message_vision("$N自言自语道：＂把这花园收拾漂亮，仙女一定还会来的。＂ \n", this_object(),ob);
         break;
   }
   return;
}
