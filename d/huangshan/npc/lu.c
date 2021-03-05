//TIE@FY3`
inherit NPC;
void create()
{
        set_name("杨绿柳", ({ "luliu" }) );
        set("gender", "男性" );
        set("age", 53);
        set("long", "
一个绿袍老人，须发都已经白了，腰杆却还是挺的笔直，眼睛发出的光芒
远比剑锋还逼人。\n");
        
        set("combat_exp", 4000000);
        set("no_busy",6);
       
        set("chat_chance", 1);
        set("chat_msg", ({
		"杨绿柳道：剑中之精，其利穿心。\n",
                (: random_move :),
        }) );
	set_skill("throwing",100);
	set_skill("feidao",100);
	map_skill("throwing","feidao");
        setup();
        carry_object(__DIR__"obj/greencloth")->wear();
	carry_object(__DIR__"obj/7inch")->wield();
}


int heal_up()
{
	if(!query_temp("right_hand")) carry_object(__DIR__"obj/7inch")->wield();
	return ::heal_up() + 1;

}
