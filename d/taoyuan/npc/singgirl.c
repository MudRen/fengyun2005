
inherit NPC;
void create()
{
	set_name("莲儿", ({ "lianer", "lian er", "莲儿" }) );
	set("gender", "女性" );
	set("age", 21);
	set("title", "卖唱女");
	set("long",
	"莲儿是瞎老爹的女儿，唱得一口好曲儿，人也出落得楚楚动人，但
眉眼中似乎总有挥不去的忧愁。
\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",30);
	set_skill("unarmed",30);
	set_skill("dodge",80);

	setup();
   carry_object(__DIR__"obj/cloth")->wear();
}

void do_sing(object ob)
{
   switch(random(2)) {
      case 0:
         message_vision("$N转过来对$n盈盈的道了个万福。\n\n",this_object(),ob);
         break;
      case 1:
         message_vision("$N低着头对$n盈盈的道了个万福。\n\n",this_object(),ob);
         break;
   }
   this_object()->set_temp("marks/song", random(2));
   this_object()->set_temp("marks/songa", 0);
   call_out("singing",2, this_object());
}

int singing (object ob)
{
   int	song, songa;
   object laodie;

   remove_call_out("singing");
   song = ob->query_temp("marks/song");
   songa = ob->query_temp("marks/songa");
   switch(song) {
      case 0:
         switch(songa) {
            case 0:
               message_vision("$N清声唱道：\n",ob);
               message_vision("        一年老一年，一日没一日，一秋又一秋，一辈催一辈，\n",ob);
               ob->set_temp("marks/songa", 1);
   call_out("singing",2,ob);
               break;
            case 1:
               message_vision("        一聚一离别，一喜一悲。一榻一身卧，一生一梦里。\n",ob);
               ob->set_temp("marks/songa", 2);
   call_out("singing",2,ob);
               break;
            case 2:
               message_vision("        寻一夥相识，他一会咱一会，都一般相知，吹一回，唱一回。\n\n",ob);
               laodie = present("lao die", environment(ob));
               if(objectp(laodie)) {
                  laodie->delete_temp("marks/sing");
               }
               break;
         }
         break;
      case 1: 
         switch(songa) {
            case 0:
   message_vision("$N轻敲竹板，婉声唱道：\n",this_object());
   message_vision("  东边路、西边路、南边路。五里铺、七里铺、十里铺。\n",this_object());
               ob->set_temp("marks/songa", 1);
   call_out("singing",2,ob);
               break;
            case 1:
   message_vision("  行一步、盼一步、懒一步。霎时间天也暮、日也暮、云也暮，\n",this_object());
               ob->set_temp("marks/songa", 2);
   call_out("singing",2,ob);
               break;
            case 2:
   message_vision("  斜阳满地铺，回首生烟雾。兀的不山无数、水无数、情无数。\n",this_object());
               laodie = present("lao die", environment(ob));
               if(objectp(laodie)) {
                  laodie->delete_temp("marks/sing");
               }
               break;
         }
         break;
   }
}
