#include <ansi.h>
inherit SMART_NPC;
int kill_him();

void create()
{

	set_name("薛斌",({"xuebin"}));
    	set("title",YEL"好汉庄老庄主"NOR);
    	set("long", "
薛斌抬起手掩住嘴，轻轻地咳嗽着，阳光照在他身上，虽然还只不过是刚升
起来的阳光，但在他感觉中，却好像是夕阳。他自己却连夕阳无限好的时光
都已过去，他的生命已到了深夜。。\n");
	set("age",69);
	set("combat_exp", 5500000);
        set("attitude", "heroism");
	
	set("inquiry", ([
             "白天羽" : (: kill_him :),
       	]));
	
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("xuebin",200,180,1,"/obj/weapon/","fighter_w","xuanyuan-axe",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	if (!random(10)) carry_object(BOOKS"axe_75");
}


int kill_him()
{
        object me/*, another*/;
        
        me = this_player();
 	if (this_object()->is_fighting()) {
 		tell_object(me,"薛斌现在没空回答你。\n");
 		return 1;
 		}
        message_vision(CYN"
薛斌道：“那次我们做的事，虽然不够光明磊落，但现在若回到十九年前，
我还是会再同样做的。。。。因为白天羽实在不是个东西。”\n"NOR,this_object());
        return 1;
}