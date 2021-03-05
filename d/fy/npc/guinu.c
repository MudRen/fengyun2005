// dtz.c

inherit NPC;
int random_action();
void create()
{
        set_name("龟奴", ({ "gui nu","nu" }) );
        set("gender", "男性" );
        set("age", random(25)+15);
        set("long", "一个为千金楼效力，正在看门的龟奴\n");
	set("per",30);
        set("combat_exp", 100000);
	set("no_arrest",1);
        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set_skill("parry", 200);
	set_skill("dodge", 200);
        set("chat_chance", 2);
        set("chat_msg", ({
                (: random_action :)
        }) );
        set("inquiry", ([
                "湖上八娇" : "哦，她们都住在荷花荡上．\n",
                "湖上柳" : "她胃口可大呢．没几两金子都别想看到她笑．\n",
                "liu" : "她胃口可大呢．没几两金子都别想看到她笑．\n",
        ]) );


	setup();
	carry_object("/obj/armor/cloth")->wear();
        
}


int accept_object(object me, object obj)
{
    command("smile");
	if (obj->query("value") >= 2000)
	{
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，您一定会．．．．！");
	me->set_temp("annie/pay_guinu",1);
	}
    return 1;
}


int random_action()
{
	int permit;
	permit=(int) environment(this_object())->query("enter_permission");
	if(!permit)
	switch(random(5)){
		case 0:
			command("zzz");
			break;
		case 1:
			command("yawn");
			break;
		case 2:
			command("bored");
			break;
			}
		else
	switch(random(5)){
	        case 0:
	message_vision("$N啧啧嘴，向你夸道：千金楼的姑娘，全城最红的！\n",this_object());
	                break;
	        case 1:
	message_vision("$N打量了你几眼：有钱就是大爷！您请上千金楼雅间！\n",this_object());
	                break;
	                }

}

void die(){
	object *inv, ob;
	int i;
	message_vision("$N惨叫一声倒了下去，楼里飞快的跑出七八个杂役抬走了$N的尸身。\n",this_object());	
	inv = all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++){
		ob = inv[i];
		if(ob->query("name") != "布衣") {
			message_vision("从$N身上掉落了一些东西。\n", this_object());
			ob->move(environment(this_object()));
		}
	}
	destruct(this_object());	
}