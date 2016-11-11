#pragma once
// many ptr and only one PefPtr,only one object 
//
namespace CamCommon
{
	template<class T>
	class SmartPtr;
	template<class T>
	class  RefPtr
	{
	private:
		friend class SmartPtr<T>;
		RefPtr(T* t) :obj(t), count(1){}
		~RefPtr(){ delete obj; }
		T* obj;
		int count;
	};
	template < class  T>
	class SmartPtr
	{
	public:
		SmartPtr(T *obj) :refPtr(new RefPtr<T>(obj)){}
		SmartPtr(const SmartPtr &sp) :refPtr(sp.refPtr){
			refPtr->count++;
		}
		~SmartPtr(){
			if (--refPtr->count == 0)
				delete refPtr;
		}
		SmartPtr& operator=(const SmartPtr& src)
		{
			if (refPtr == src.refPtr)
				return *this;
			// release old
			releaseCount();
			refPtr = src.refPtr;
			refPtr->count++;
			return *this;
		}
		T& operator*(){
			return *(refPtr->obj);
		}
		T* operator->(){
			return refPtr->obj;
		}
	private:
		RefPtr<T>* refPtr;
		void releaseCount()
		{
			if (refPtr)
			{
				refPtr->count--;
				if (refPtr->count == 0)
				{
					delete refPtr;
				}
			}
		}
	};
}
