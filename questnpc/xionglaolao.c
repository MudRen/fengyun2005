#include <ansi.h>
#include <combat.h>

inherit NPC;

void do_fight();
object offensive_target(object me);
void create()
{
	set_name("熊姥姥", ({ "xiong laolao", "laolao" }) );
	set("gender", "女性" );
	set("title", "圆月杀人    夜枭");
	set("nickname",YEL"糖炒栗子"NOR);
    set("age", 58);
	set("int", 65);
	set("per", 5);
	set("str", 50);
	set("fle", 50);
	set("dur", 42);
	set("cor", 60);
	set("agi",80);
    set("long",
"她似乎就好像幽灵般忽然间就在浓雾里。她背上仿佛压着块看不见的大石头，压得\n
她整个人都弯曲了起来，连腰都似巳被压断。\n
她手里提着个很古怪的竹篮子，用一块很厚的棉布紧紧盖着。
\n");
        set("force_factor", 120);
        set("max_force",9000);
	set("force",9000);

        set("combat_exp", 10000000);
        set("score", -90000);
        set_skill("unarmed", 220);
        set_skill("throwing", 200);
        set_skill("force", 300);
        set_skill("parry", 450);
        set_skill("literate", 110);
	set_skill("dodge", 350);
	set_skill("demon-force", 250);
	set_skill("demon-strike",300);
	set_skill("demon-steps",200);
	
		
	map_skill("force", "demon-force");
	map_skill("unarmed","demon-strike");
	map_skill("dodge","demon-steps");
	map_skill("move","demon-steps");
	map_skill("throwing","tanzhi-shentong");
	set("chat_chance",3);
	set("chat_msg",({
		"熊姥姥眯起眼睛，似乎望着天边，喃喃地说：“每当月圆的时候，我就想杀人。”\n",
		"熊姥姥皱起纹路纵横的老脸，对你笑了笑：“刚出锅的糖炒栗子，要不要尝尝？”\n",
		"“糖炒栗子。”熊姥姥满是皱纹的脸上露出笑容“又香又热的糖炒栗子，才十文钱一斤。”\n",
		})	
	);
      
	setup();
	/*
	carry_object(__DIR__"obj/grey_cloth")->wear();
	carry_object(__DIR__"obj/owl_shoes")->wear();
	carry_object(__DIR__"obj/nut_basket");
	carry_object(__DIR__"obj/fried_nuts");
	*/
}


void heart_beat()
{
	::heart_beat();
	if(is_fighting())
		command("rush");
		//smart_fight();
}

