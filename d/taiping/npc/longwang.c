#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

void create()
{

	set_name("海龙王",({"long wang","wang"}));
    set("title","东海一霸");
    set("long", "海龙王吃完了他用生虾片夹着的饭团，正用一块柔绢抹着嘴。他喜欢吃生鱼活虾，
这是他早年纵横七海时养成的习惯，这种食物总是能令他精力充沛。。\n");
	set("age",40);
	set("combat_exp", 4000000);
        	
	set("reward_npc", 3);
		
	set("chat_chance", 1);
    set("chat_msg", ({
        	"海龙王伸出手去摸了摸女孩的脸，心满意足地笑了。\n",
        	"海龙王拍了拍你的肩说：女人的呼喊和呻吟声，倒在身下挣扎的样子，是最迷人的。\n",
        }) );

	
   	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
       }) );
    	    	
    auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","shenji-blade",1);
	setup();
	carry_object(__DIR__"obj/7blade")->wield();
}


void init()
{
    ::init();	
    add_action("do_look", "look");
}


int do_look(string arg)
{
    object me,girl;
    me = this_player();
    
    if (girl=present("naked girl",environment(this_object())))
    if( arg == "naked girl" || arg == "girl" )
    {
        message_vision(CYN"$N拍了拍你的肩膀说：怎么样？秀色可餐，拿点金子来，你想怎么玩就怎么玩。\n\n"NOR, this_object());
        return 0;
    }
    else return 0;
}

int accept_object(object who, object ob)
{
	if( ob->value() >= 10000) {
        command("spank "+this_player()->get_id());
        who->set_temp("taiping/longwang_kill",1) ;
        message_vision(CYN"海龙王拿了个枕头往床上一靠，舒舒服服地找了个姿势。\n"NOR,who);
        command("say 好，今天老子换换口味，就看看你怎么摆弄这小妞了。\n");
        return 1;
	} else {
    	command("shake");
    	command("say 就值这么点？");
        return 0;
	}
       return 0;
} 

