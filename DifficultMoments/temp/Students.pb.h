// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Students.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Students_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Students_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Students_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Students_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Students_2eproto;
namespace Univer {
class FullName;
struct FullNameDefaultTypeInternal;
extern FullNameDefaultTypeInternal _FullName_default_instance_;
class Student;
struct StudentDefaultTypeInternal;
extern StudentDefaultTypeInternal _Student_default_instance_;
class StudentsGroup;
struct StudentsGroupDefaultTypeInternal;
extern StudentsGroupDefaultTypeInternal _StudentsGroup_default_instance_;
}  // namespace Univer
PROTOBUF_NAMESPACE_OPEN
template<> ::Univer::FullName* Arena::CreateMaybeMessage<::Univer::FullName>(Arena*);
template<> ::Univer::Student* Arena::CreateMaybeMessage<::Univer::Student>(Arena*);
template<> ::Univer::StudentsGroup* Arena::CreateMaybeMessage<::Univer::StudentsGroup>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Univer {

// ===================================================================

class FullName final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Univer.FullName) */ {
 public:
  inline FullName() : FullName(nullptr) {}
  ~FullName() override;
  explicit constexpr FullName(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  FullName(const FullName& from);
  FullName(FullName&& from) noexcept
    : FullName() {
    *this = ::std::move(from);
  }

  inline FullName& operator=(const FullName& from) {
    CopyFrom(from);
    return *this;
  }
  inline FullName& operator=(FullName&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const FullName& default_instance() {
    return *internal_default_instance();
  }
  static inline const FullName* internal_default_instance() {
    return reinterpret_cast<const FullName*>(
               &_FullName_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(FullName& a, FullName& b) {
    a.Swap(&b);
  }
  inline void Swap(FullName* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(FullName* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  FullName* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<FullName>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const FullName& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const FullName& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FullName* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Univer.FullName";
  }
  protected:
  explicit FullName(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kSurnameFieldNumber = 2,
    kPatronymicFieldNumber = 3,
  };
  // required string name = 1;
  bool has_name() const;
  private:
  bool _internal_has_name() const;
  public:
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // required string surname = 2;
  bool has_surname() const;
  private:
  bool _internal_has_surname() const;
  public:
  void clear_surname();
  const std::string& surname() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_surname(ArgT0&& arg0, ArgT... args);
  std::string* mutable_surname();
  PROTOBUF_NODISCARD std::string* release_surname();
  void set_allocated_surname(std::string* surname);
  private:
  const std::string& _internal_surname() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_surname(const std::string& value);
  std::string* _internal_mutable_surname();
  public:

  // optional string patronymic = 3;
  bool has_patronymic() const;
  private:
  bool _internal_has_patronymic() const;
  public:
  void clear_patronymic();
  const std::string& patronymic() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_patronymic(ArgT0&& arg0, ArgT... args);
  std::string* mutable_patronymic();
  PROTOBUF_NODISCARD std::string* release_patronymic();
  void set_allocated_patronymic(std::string* patronymic);
  private:
  const std::string& _internal_patronymic() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_patronymic(const std::string& value);
  std::string* _internal_mutable_patronymic();
  public:

  // @@protoc_insertion_point(class_scope:Univer.FullName)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr surname_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr patronymic_;
  friend struct ::TableStruct_Students_2eproto;
};
// -------------------------------------------------------------------

class Student final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Univer.Student) */ {
 public:
  inline Student() : Student(nullptr) {}
  ~Student() override;
  explicit constexpr Student(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Student(const Student& from);
  Student(Student&& from) noexcept
    : Student() {
    *this = ::std::move(from);
  }

  inline Student& operator=(const Student& from) {
    CopyFrom(from);
    return *this;
  }
  inline Student& operator=(Student&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Student& default_instance() {
    return *internal_default_instance();
  }
  static inline const Student* internal_default_instance() {
    return reinterpret_cast<const Student*>(
               &_Student_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Student& a, Student& b) {
    a.Swap(&b);
  }
  inline void Swap(Student* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Student* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Student* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Student>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Student& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Student& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Student* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Univer.Student";
  }
  protected:
  explicit Student(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kScoresFieldNumber = 2,
    kNameFieldNumber = 1,
    kAverageScoreFieldNumber = 3,
  };
  // repeated int32 scores = 2;
  int scores_size() const;
  private:
  int _internal_scores_size() const;
  public:
  void clear_scores();
  private:
  int32_t _internal_scores(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      _internal_scores() const;
  void _internal_add_scores(int32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      _internal_mutable_scores();
  public:
  int32_t scores(int index) const;
  void set_scores(int index, int32_t value);
  void add_scores(int32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      scores() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      mutable_scores();

  // required .Univer.FullName name = 1;
  bool has_name() const;
  private:
  bool _internal_has_name() const;
  public:
  void clear_name();
  const ::Univer::FullName& name() const;
  PROTOBUF_NODISCARD ::Univer::FullName* release_name();
  ::Univer::FullName* mutable_name();
  void set_allocated_name(::Univer::FullName* name);
  private:
  const ::Univer::FullName& _internal_name() const;
  ::Univer::FullName* _internal_mutable_name();
  public:
  void unsafe_arena_set_allocated_name(
      ::Univer::FullName* name);
  ::Univer::FullName* unsafe_arena_release_name();

  // required int32 averageScore = 3;
  bool has_averagescore() const;
  private:
  bool _internal_has_averagescore() const;
  public:
  void clear_averagescore();
  int32_t averagescore() const;
  void set_averagescore(int32_t value);
  private:
  int32_t _internal_averagescore() const;
  void _internal_set_averagescore(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:Univer.Student)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t > scores_;
  ::Univer::FullName* name_;
  int32_t averagescore_;
  friend struct ::TableStruct_Students_2eproto;
};
// -------------------------------------------------------------------

class StudentsGroup final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Univer.StudentsGroup) */ {
 public:
  inline StudentsGroup() : StudentsGroup(nullptr) {}
  ~StudentsGroup() override;
  explicit constexpr StudentsGroup(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  StudentsGroup(const StudentsGroup& from);
  StudentsGroup(StudentsGroup&& from) noexcept
    : StudentsGroup() {
    *this = ::std::move(from);
  }

  inline StudentsGroup& operator=(const StudentsGroup& from) {
    CopyFrom(from);
    return *this;
  }
  inline StudentsGroup& operator=(StudentsGroup&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const StudentsGroup& default_instance() {
    return *internal_default_instance();
  }
  static inline const StudentsGroup* internal_default_instance() {
    return reinterpret_cast<const StudentsGroup*>(
               &_StudentsGroup_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(StudentsGroup& a, StudentsGroup& b) {
    a.Swap(&b);
  }
  inline void Swap(StudentsGroup* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(StudentsGroup* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  StudentsGroup* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<StudentsGroup>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const StudentsGroup& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const StudentsGroup& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(StudentsGroup* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Univer.StudentsGroup";
  }
  protected:
  explicit StudentsGroup(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStudentsFieldNumber = 1,
  };
  // repeated .Univer.Student students = 1;
  int students_size() const;
  private:
  int _internal_students_size() const;
  public:
  void clear_students();
  ::Univer::Student* mutable_students(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Univer::Student >*
      mutable_students();
  private:
  const ::Univer::Student& _internal_students(int index) const;
  ::Univer::Student* _internal_add_students();
  public:
  const ::Univer::Student& students(int index) const;
  ::Univer::Student* add_students();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Univer::Student >&
      students() const;

  // @@protoc_insertion_point(class_scope:Univer.StudentsGroup)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Univer::Student > students_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Students_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FullName

// required string name = 1;
inline bool FullName::_internal_has_name() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool FullName::has_name() const {
  return _internal_has_name();
}
inline void FullName::clear_name() {
  name_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& FullName::name() const {
  // @@protoc_insertion_point(field_get:Univer.FullName.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FullName::set_name(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Univer.FullName.name)
}
inline std::string* FullName::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:Univer.FullName.name)
  return _s;
}
inline const std::string& FullName::_internal_name() const {
  return name_.Get();
}
inline void FullName::_internal_set_name(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FullName::_internal_mutable_name() {
  _has_bits_[0] |= 0x00000001u;
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FullName::release_name() {
  // @@protoc_insertion_point(field_release:Univer.FullName.name)
  if (!_internal_has_name()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  auto* p = name_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void FullName::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Univer.FullName.name)
}

// required string surname = 2;
inline bool FullName::_internal_has_surname() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool FullName::has_surname() const {
  return _internal_has_surname();
}
inline void FullName::clear_surname() {
  surname_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& FullName::surname() const {
  // @@protoc_insertion_point(field_get:Univer.FullName.surname)
  return _internal_surname();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FullName::set_surname(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000002u;
 surname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Univer.FullName.surname)
}
inline std::string* FullName::mutable_surname() {
  std::string* _s = _internal_mutable_surname();
  // @@protoc_insertion_point(field_mutable:Univer.FullName.surname)
  return _s;
}
inline const std::string& FullName::_internal_surname() const {
  return surname_.Get();
}
inline void FullName::_internal_set_surname(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  surname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FullName::_internal_mutable_surname() {
  _has_bits_[0] |= 0x00000002u;
  return surname_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FullName::release_surname() {
  // @@protoc_insertion_point(field_release:Univer.FullName.surname)
  if (!_internal_has_surname()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  auto* p = surname_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (surname_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    surname_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void FullName::set_allocated_surname(std::string* surname) {
  if (surname != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  surname_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), surname,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (surname_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    surname_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Univer.FullName.surname)
}

// optional string patronymic = 3;
inline bool FullName::_internal_has_patronymic() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool FullName::has_patronymic() const {
  return _internal_has_patronymic();
}
inline void FullName::clear_patronymic() {
  patronymic_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000004u;
}
inline const std::string& FullName::patronymic() const {
  // @@protoc_insertion_point(field_get:Univer.FullName.patronymic)
  return _internal_patronymic();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FullName::set_patronymic(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000004u;
 patronymic_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Univer.FullName.patronymic)
}
inline std::string* FullName::mutable_patronymic() {
  std::string* _s = _internal_mutable_patronymic();
  // @@protoc_insertion_point(field_mutable:Univer.FullName.patronymic)
  return _s;
}
inline const std::string& FullName::_internal_patronymic() const {
  return patronymic_.Get();
}
inline void FullName::_internal_set_patronymic(const std::string& value) {
  _has_bits_[0] |= 0x00000004u;
  patronymic_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FullName::_internal_mutable_patronymic() {
  _has_bits_[0] |= 0x00000004u;
  return patronymic_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FullName::release_patronymic() {
  // @@protoc_insertion_point(field_release:Univer.FullName.patronymic)
  if (!_internal_has_patronymic()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000004u;
  auto* p = patronymic_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (patronymic_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    patronymic_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void FullName::set_allocated_patronymic(std::string* patronymic) {
  if (patronymic != nullptr) {
    _has_bits_[0] |= 0x00000004u;
  } else {
    _has_bits_[0] &= ~0x00000004u;
  }
  patronymic_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), patronymic,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (patronymic_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    patronymic_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Univer.FullName.patronymic)
}

// -------------------------------------------------------------------

// Student

// required .Univer.FullName name = 1;
inline bool Student::_internal_has_name() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || name_ != nullptr);
  return value;
}
inline bool Student::has_name() const {
  return _internal_has_name();
}
inline void Student::clear_name() {
  if (name_ != nullptr) name_->Clear();
  _has_bits_[0] &= ~0x00000001u;
}
inline const ::Univer::FullName& Student::_internal_name() const {
  const ::Univer::FullName* p = name_;
  return p != nullptr ? *p : reinterpret_cast<const ::Univer::FullName&>(
      ::Univer::_FullName_default_instance_);
}
inline const ::Univer::FullName& Student::name() const {
  // @@protoc_insertion_point(field_get:Univer.Student.name)
  return _internal_name();
}
inline void Student::unsafe_arena_set_allocated_name(
    ::Univer::FullName* name) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(name_);
  }
  name_ = name;
  if (name) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Univer.Student.name)
}
inline ::Univer::FullName* Student::release_name() {
  _has_bits_[0] &= ~0x00000001u;
  ::Univer::FullName* temp = name_;
  name_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::Univer::FullName* Student::unsafe_arena_release_name() {
  // @@protoc_insertion_point(field_release:Univer.Student.name)
  _has_bits_[0] &= ~0x00000001u;
  ::Univer::FullName* temp = name_;
  name_ = nullptr;
  return temp;
}
inline ::Univer::FullName* Student::_internal_mutable_name() {
  _has_bits_[0] |= 0x00000001u;
  if (name_ == nullptr) {
    auto* p = CreateMaybeMessage<::Univer::FullName>(GetArenaForAllocation());
    name_ = p;
  }
  return name_;
}
inline ::Univer::FullName* Student::mutable_name() {
  ::Univer::FullName* _msg = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:Univer.Student.name)
  return _msg;
}
inline void Student::set_allocated_name(::Univer::FullName* name) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete name_;
  }
  if (name) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<::Univer::FullName>::GetOwningArena(name);
    if (message_arena != submessage_arena) {
      name = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, name, submessage_arena);
    }
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  name_ = name;
  // @@protoc_insertion_point(field_set_allocated:Univer.Student.name)
}

// repeated int32 scores = 2;
inline int Student::_internal_scores_size() const {
  return scores_.size();
}
inline int Student::scores_size() const {
  return _internal_scores_size();
}
inline void Student::clear_scores() {
  scores_.Clear();
}
inline int32_t Student::_internal_scores(int index) const {
  return scores_.Get(index);
}
inline int32_t Student::scores(int index) const {
  // @@protoc_insertion_point(field_get:Univer.Student.scores)
  return _internal_scores(index);
}
inline void Student::set_scores(int index, int32_t value) {
  scores_.Set(index, value);
  // @@protoc_insertion_point(field_set:Univer.Student.scores)
}
inline void Student::_internal_add_scores(int32_t value) {
  scores_.Add(value);
}
inline void Student::add_scores(int32_t value) {
  _internal_add_scores(value);
  // @@protoc_insertion_point(field_add:Univer.Student.scores)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
Student::_internal_scores() const {
  return scores_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
Student::scores() const {
  // @@protoc_insertion_point(field_list:Univer.Student.scores)
  return _internal_scores();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
Student::_internal_mutable_scores() {
  return &scores_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
Student::mutable_scores() {
  // @@protoc_insertion_point(field_mutable_list:Univer.Student.scores)
  return _internal_mutable_scores();
}

// required int32 averageScore = 3;
inline bool Student::_internal_has_averagescore() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool Student::has_averagescore() const {
  return _internal_has_averagescore();
}
inline void Student::clear_averagescore() {
  averagescore_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline int32_t Student::_internal_averagescore() const {
  return averagescore_;
}
inline int32_t Student::averagescore() const {
  // @@protoc_insertion_point(field_get:Univer.Student.averageScore)
  return _internal_averagescore();
}
inline void Student::_internal_set_averagescore(int32_t value) {
  _has_bits_[0] |= 0x00000002u;
  averagescore_ = value;
}
inline void Student::set_averagescore(int32_t value) {
  _internal_set_averagescore(value);
  // @@protoc_insertion_point(field_set:Univer.Student.averageScore)
}

// -------------------------------------------------------------------

// StudentsGroup

// repeated .Univer.Student students = 1;
inline int StudentsGroup::_internal_students_size() const {
  return students_.size();
}
inline int StudentsGroup::students_size() const {
  return _internal_students_size();
}
inline void StudentsGroup::clear_students() {
  students_.Clear();
}
inline ::Univer::Student* StudentsGroup::mutable_students(int index) {
  // @@protoc_insertion_point(field_mutable:Univer.StudentsGroup.students)
  return students_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Univer::Student >*
StudentsGroup::mutable_students() {
  // @@protoc_insertion_point(field_mutable_list:Univer.StudentsGroup.students)
  return &students_;
}
inline const ::Univer::Student& StudentsGroup::_internal_students(int index) const {
  return students_.Get(index);
}
inline const ::Univer::Student& StudentsGroup::students(int index) const {
  // @@protoc_insertion_point(field_get:Univer.StudentsGroup.students)
  return _internal_students(index);
}
inline ::Univer::Student* StudentsGroup::_internal_add_students() {
  return students_.Add();
}
inline ::Univer::Student* StudentsGroup::add_students() {
  ::Univer::Student* _add = _internal_add_students();
  // @@protoc_insertion_point(field_add:Univer.StudentsGroup.students)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Univer::Student >&
StudentsGroup::students() const {
  // @@protoc_insertion_point(field_list:Univer.StudentsGroup.students)
  return students_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Univer

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Students_2eproto
