// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;

void create()
{
	object obj;
	set_name("潇潇", ({ "xiao xiao", "xiao" }) );
	set("class","moon");
	set("gender", "女性" );
	set("age", 25);

	set("nickname",HIG"花明月黯飞轻雾"NOR);
	set("title","皓月宫"NOR);

	set("attitude", "friendly");

	set("long","她正倚着一竿修竹，闭目沉思。\n");

	set("inquiry",([
       	"月神": 	"素姐姐？她出门去了。\n",
      	"李坏": 	"哼……\n",
    	]) );

	set("combat_exp", 4400000);

/*	set_skill("starrain", 200);
	set_skill("throwing", 300);
	map_skill("throwing","starrain");

	set_skill("force", 200);
	set_skill("snowforce", 200);
	map_skill("force","snowforce");

	set_skill("dodge", 200);
	set_skill("move", 200);
	set_skill("stormdance", 140);
	map_skill("dodge","stormdance");
	map_skill("move","stormdance");

	set_skill("unarmed",200);
	set_skill("lingxi-zhi",200);
	map_skill("unarmed","lingxi-zhi");*/
	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(5) :),
     }) ); 		

	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","fengloufeiyan",1);
	set_skill("stormdance", 140);
	setup();

	obj=carry_object(__DIR__"obj/ccloth");
	obj->set("name","织月青衣");
	obj->delete("long");
	obj->wear();
	carry_object(__DIR__"obj/feidao2")->wield();

}


void die()
{
	ccommand("perform xueyuezhonghua");
//	ccommand("say "+ccommand("perform xueyuezhonghua"));
	::die();
}