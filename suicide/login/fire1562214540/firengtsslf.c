#include <ansi.h>
#include <weapon.h>
inherit SPEAR;
void create()
{
        set_name( NOR "潜龙戟" NOR, ({ "spear" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根长矛\n");
                set("no_drop",1);
                set("timestamp","ngtsslf");
                set("no_get",1);
                set("owner","fire");
                set("rigidity",300);
		set("material", "iron");
		set("wield_msg", "$N拿出一根$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	::init_spear(30);
}

string query_save_file()
{
        string id;

        id = query("owner");
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s/%s", id[0],id, id+"."+query("timestamp"));
}

int save()
{
        string file;
        string equipped;
        int result;
        if( stringp(file = this_object()->query_save_file()) ) {
                equipped = (string)query("equipped");
                delete("equipped");
                assure_file(file+ __SAVE_EXTENSION__);
                result = save_object(file,1);
                set("equipped",equipped);
                return result;
        }
        return 0;
}
int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
        if(restore_object(file))
        {
                set_weight(query("weight"));
                return 1;
        }
        return 0;
}

