inherit NPC;
#include <ansi.h>

void create()
{
    	set_name("碧莲",({"bilian"}));
    	set("title",YEL"鹦鹉楼"NOR);
    	set("long","
腮凝新荔，鼻腻鹅脂，碧莲其实不是她的真名，不过从打小儿被卖到鹦鹉楼，
没有人知道，也没有人关心过她的真名字。碧莲原来只是跟着作些打酒儿唱
曲子，渐渐长成了，鸨儿就想着这棵摇钱树了。\n");
    	set("gender","女性");
    	set("age",15);
    	set("no_arrest",1);
    	set("per",60);
    	
    	set("combat_exp",250000);  
    	set("attitude", "friendly");
    
   	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	]) ); 
    	
    	set("chat_chance",1);
    	set("chat_msg",({
//		"碧莲满脸通红，低著头一声不吭。”\n",	
    	}) );
    	setup();    
	carry_object(__DIR__"obj/ladycloth2")->wear();
}


void init()	{
	::init();
	add_action("do_enjoy","enjoy");
}


int 	do_enjoy(){
	message_vision(CYN"$N说：“要我会客，除非见了亲生爹妈。他肯做主时，方才使得。”\n"NOR,this_object());
	return 1;
}
