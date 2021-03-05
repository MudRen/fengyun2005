inherit ITEM;

void create() {
	set_name("死狼", ({ "deadwolf" }) );	
	set_weight(80000);
	set("long", "这条死狼摔得皮破肉烂，脑壳扁扁。因为颌骨 
摔变形了，一嘴利牙都呲了出来，怪吓人的。也
不知道从多高的地方掉下来才能摔成这样。 \n");
	set("unit", "具" );
	set("value", 1);
	set("deadwolf",1);
    if( clonep() )
       set_default_object(__FILE__);

}

