#include <ansi.h>
inherit SMART_NPC;

int talk_show();

void create()
{
        set_name("满脸风霜的老乞丐", ({ "beggar courier"}) );
        set("gender", "男性" );
        set("age", 53);
        set("long", "一个满脸风霜之色的老乞丐，正机警察看着周围地形。\n");
        set("combat_exp", 4000000);
		set("altitude", "friendly");			
		set("title","丐帮九袋弟子");
		set("class","beggar");
        set("inform_target",1);
        
		set("chat_chance",1);
    	set("chat_msg",({
			"老乞丐左右手各执两块小竹板，上下敲击，高声唱起了"YEL"莲花落"CYN"。\n"NOR,
    	}) );  
                
        set("inquiry", ([
        	"莲花落":	(: talk_show() :),
        ]));
                      
        set("chat_chance_combat", 100);
	    set("chat_msg_combat", ({
		     (: auto_smart_fight(20) :),
	     }) ); 		
	
		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","dragonstrike",1);
        setup();
        carry_object("obj/armor/cloth")->wear();
}

int talk_show() {
	object ob,girl;
	ob=this_object();
	if (!this_player())	return 1;
			
	if (ob->query_temp("talking")) return 1;
	message_vision("\n老乞丐左右手各执两块小竹板，上下敲击，高声唱道：\n\n"NOR,ob);
	call_out("event1",1,this_player(),0);
	ob->set_temp("talking",1);
	return 1;
}

string *event1_msg=	({
	CYN"\n    提提嗒，提提嗒，提提嗒提嗒提嗒。\n"NOR,
	CYN"    一张嘴来一副板，各位看官听我唱：\n"NOR,
 	CYN"    问我有啥苦与难，一把泪水一声叹。\n"NOR,
	CYN"    莲花乐，莲花落，开一朵，落一朵。\n"NOR,
    CYN"    莲花本俗物，奈何已上天，美人本妖娆，怎么也成仙？\n"NOR,
	CYN"    美女上了天，叫俺好心酸，饭也没人做，被窝没人暖。\n"NOR,
 	CYN"    有钱时，俺也是高车驰马着锦袍，四书五经读朝朝。\n"NOR,
	CYN"    落魄时，俺也能风里浪里游四方，天当被来地当床。\n"NOR,
    CYN"    只是没了美人伴，长夜漫漫不能眠啊，不能眠！\n"NOR,
});

	
void event1(object me, int count)
{
	object ob,girl;
	ob=this_object();
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	
	message_vision(event1_msg[count]+"\n",me);
	
	if(++count==sizeof(event1_msg))
	{
		message_vision(CYN"    。。。。。。。\n\n"NOR,me);
		ob->delete_temp("talking");
		return;
	}
	else call_out("event1",2,me,count);
	return ;
}	

    	
