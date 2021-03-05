inherit NPC;

void create()
{
        set_name("阿黄", ({ "yellow dog", "dog", "阿黄" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", 
	"一个在阳光下懒洋洋的好狗．．．阿黄天真的望著你，最喜欢你拍拍它的头。\n"
	);
        set("max_kee", 150);
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite" }) );

	set("combat_exp", 5000);
        set_skill("dodge", 100);

        setup();
}
void init()
{
   object ob;
	
   ::init();
   if( interactive(ob = this_player()) && !is_fighting() ) {
      remove_call_out("greeting");
      call_out("greeting", 1, ob);
   }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
message_vision("$N看见$n来，高兴的摇摇尾巴，爬起来蹭在$n身边嗅了嗅。\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N对着$n汪汪地叫了几声。\n",this_object(),ob);
                        break;
                case 2:
message_vision("$N望了$n一眼，又懒洋洋地躺下。\n",this_object(),ob);
                        break;
        }
}

