#include <ansi.h>
inherit NPC;
void create()
{
        set_name("红娘子", ({ "hong niangzi", "hong" }) );
        set("gender", "女性" );
        set("long",
         "她身上好像也在发光，一种红得耀眼，红得令人心跳的光。红娘子身\n上当然穿着红衣服，但光不是从她衣服上发出来的，事实上除了衣服\n外，她身上每个地方好像都在发光，尤其是她的眼睛，她的笑。\n");
        set("nickname", HIR "救苦救难"NOR);
        set("chat_chance",1);
        set("chat_msg", ({
        "红娘子眼波流动，向你抛了个媚眼，似笑非笑道：“我长得怎样？你\n动不动心啊？”\n",
                                })  );

       	set("combat_exp", 1000000);
        set("no_arrest",1);
        
        set_skill("unarmed", 150);
        set_skill("force",100);
        set_skill("parry",180);
        set_skill("dodge", 120);
        set_skill("move",120);
        set_skill("cloudforce",60);
        set_skill("chaos-steps",150);
        set_skill("tigerstrike",150);
        
        map_skill("unarmed","tigerstrike");
        map_skill("dodge","chaos-steps");
        map_skill("move","chaos-steps");
        map_skill("force","cloudforce");
        
        setup();
	carry_object(__DIR__"obj/redcloth")->wear();
}

void init()
{	
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) 
		return;
	message_vision(HIW"$N眼波流动，瞟了$n一眼，似笑非笑道：“我早知道会有人来的，\n怎么王动他自己不来？哎，解药就在坟头，自己去拿吧。”\n"NOR,this_object(),ob);
		
}
