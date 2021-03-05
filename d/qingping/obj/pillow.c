inherit ITEM;
void create()
{
   set_name("竹夫人", ({ "bamboo pillow", "竹夫人", "pillow" }) );
   set_weight(500);
   set_max_encumbrance(100);

   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "in");
      set("unit", "个");
      set("long", "这是个用竹子做成的小枕头，又俗称竹夫人。\n");
      set("value", 100);
   }
}

int is_container() { return 1; }

void init()
{
   add_action("do_open", "open");
}

int do_open(string arg)
{
   object me, item, ob;

   me = this_player();
   ob = this_object();
   if (!arg || (arg != "bamboo pillow" && arg != "竹夫人" && arg != "pillow"))
      return 0; 
   if(ob->query_temp("marks/opened"))
      return 0;
   message_vision("$N小心翼翼地把竹夫人从侧面打开。\n",me);
   set("long", "竹子做成的小枕头，被人从侧面打开了。\n");
   item = new(__DIR__"paper1");
   item->move(ob);   
   ob->set_temp("marks/opened", 1);
   return 1;
   
}
