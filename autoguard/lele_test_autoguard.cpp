template <typename SyncPrim, void (SyncPrim::*lock_func)() const, void (SyncPrim::*unlock_func)() const>
class SyncGuardFunc
{
public:
	SyncGuardFunc(const SyncPrim &m) : sp(&m)
	{
	}

	~SyncGuardFunc()
	{
		if (sp)	
		{
			sp->*unlock_func();	
		}
	}

	void lock()
	{
		if (sp)	
		{
			sp->*lock_func();	
		}
	}

	void unlock()
	{
		if (sp)	
		{
			sp->*unlock_func();	
		}
	}

	void attach(const SyncPrim &);
	void detach();
private:
	const SyncPrim *sp;
	SyncGuardFunc(const SyncGuardFunc &);
	SyncGuardFunc &operator = (const SyncGuardFunc &);
};
