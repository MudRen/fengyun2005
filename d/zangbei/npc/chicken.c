#include <ansi.h>
inherit SMART_NPC;
int escape();

void create()
{
        set_name("藏马鸡", ({ "bird","chicken","crossoptilon" }) );
        set("race", "飞禽");
        set("age", 10);
        set("long", "
一只白色的藏马鸡，头部两侧红色，头顶上生有密密的黑色短的绒状羽
毛。耳羽呈簇状，白色，像两个短角向后延伸着。它正在地上蹦蹦跳跳
地寻找食物。\n");
        
	set_skill("move",2000);
	set("chaser",1);
	set("combat_exp", 300000);
    	
    	set("max_kee",1200);
    	set("max_sen",600);
    	set("max_gin",600);
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		100:	(: escape() :),
        ]) ); 
   	
    	set("chat_chance",1);
    	set("chat_msg",({
		CYN"咯咯，咯咯，藏马鸡欢快地叫了起来。\n"NOR,
		"藏马鸡扑闪着翅膀飞了起来，落到空地的另一边。\n",
    	}) );  	
        setup();
}


int escape(){
	object /*ob,*/*env,room;
	int i;
	
	if (environment(this_object())->query("in_tree")) return 1;
	
	message_vision(CYN"\n"+name()+"咯咯咯地惊叫着，拍打着翅膀飞上了旁边的大松树，唉，看来白忙乎了。\n"NOR,this_object());
	env=all_inventory(environment(this_object()));
	for (i=0;i<sizeof(env);i++)
		if(userp(env[i])) env[i]->set_temp("marks/zangbei/马鸡上树",1);
	room=find_object(AREA_ZANGBEI"pine2");
	if (!objectp(room)) room=load_object(AREA_ZANGBEI"pine2");
	this_object()->move(room);
	return 1;	
}	