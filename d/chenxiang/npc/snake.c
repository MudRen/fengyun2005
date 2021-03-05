inherit NPC;
void use_poison();

void create()
{
        set_name("巨花蟒", ({ "huge serpent" }) );
        set("race", "蛇类");
        set("age", 400);
        set("long", "这蟒巨大无比，浑身都长满了毒瘤，毒瘤上还冒着脓血。\n");
        
        set_skill("dodge", 200);
        set_temp("apply/damage",100);
        set("combat_exp", 2999999);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        setup();
		
}


void use_poison()
{
        object *enemy, ob;
//      string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        tell_object(ob,"你觉得腿上剧痛，伸手一摸发现两个毒牙印痕。\n");
		ob->receive_wound("kee",40);
                ob->apply_condition("snake_poison", 
                (int)this_player()->query_condition("snake_poison")
                + random(10)+10);
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !ob->query_temp("marks/cured_jia") ) {
                kill_ob(ob);
        }
}



int cure_arong(object me)
{
	 object room,obj;
 	if(!query("cured") && me->query_temp("marks/cured_monk") &&
        	               me->query_temp("marks/cured_jia") &&
				!me->query_temp("marks/cured_snake")) {
 		tell_object(me,"巨花蟒身上的毒瘤和脓血都开始慢慢地消失了．．．\n");
 		tell_object(me,"巨花蟒抬起尾巴在你的身上蹭了蹭，似乎表达对你的感谢！\n");
 		me->set_temp("marks/cured_snake",1);
 		tell_object(me,"巨花蟒从嘴里吐出个又大又亮的珠子，然后用尾巴卷住你往上用力一抛．．．\n\n\n");
 		tell_object(me,"你身体腾空而起．．．哦喔．．．．．．\n\n\n");
 		set("cured",1);
 		obj = new(__DIR__"obj/pearl");
 		obj->move(me);
 		room = load_object(AREA_CHENXIANG"wol2");
 		me->move(room);
 		me->delete_temp("marks/cured_monk");
 		me->delete_temp("marks/cured_jia");
 		me->delete_temp("marks/cured_snake");
 		me->delete_temp("marks/asked_jianu");
 	} 
 	return 1;

}


int	reset(){
	set("cured",0);
}