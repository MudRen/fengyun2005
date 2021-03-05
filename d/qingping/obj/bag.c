//XXDER
inherit ITEM;
void create()
{
   set_name("锦囊", ({ "silk bag", "锦囊"}) );
   set_weight(50);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("unit", "个");
      set("long", "这是一个精致的锦囊。\n");
      set("value", 100);
   }
}

void init()
{
   add_action("do_open", "open");
}

int do_open(string arg)
{
   if( arg != "silk bag" ) return 0;
   tell_object(this_player(),"汝开此囊之时，吾必丧于白衣人之手，速去东海之滨，
寻五色锦帆船，将信呈上，可消弥此祸。\n");
   return 1;
}
