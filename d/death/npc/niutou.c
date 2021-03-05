inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIW"牛头"NOR, ({ "niutou" }) );
        set("gender", "男性" );
        set("age", 25);
		set("title", HIW "铁索"NOR);
        	
        set_temp("apply/astral_vision",1);

        set("intellgent",1);
        set("attitude", "peaceful");
        
        set("long",     "牛面人身，全身青紫的鬼怪。\n");


		
		set("inquiry", ([
          	"明烟草" : 	"action牛头叽叽喳喳一阵乱叫，可惜你什么也听不懂。\n",
      	]) );
		
        set("combat_exp", 30000);
		set_skill("parry",100);
        set_skill("whip", 120);
		set_skill("dodge", 100);
        setup();
        carry_object(__DIR__"obj/whip")->wield();
        carry_object("/obj/armor/ghost_cloth")->wear();
}


int accept_object(object who, object ob)
{
		message_vision("$N对$n怪叫一声：在阳间做亏心事了吧！\n",this_object(),who);
		return 1;
}
